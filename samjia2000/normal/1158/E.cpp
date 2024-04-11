#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1005;

int n;
int dis[N];
char s[N];
bool can[N];

void query(){
	printf("?");
	fo(i,1,n)printf(" %d",dis[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",s+1);
	fo(i,1,n)can[i]=s[i]-'0';
}

vector<int>pt[N],que[N];
int key[N],k;
int d[N];
bool can0[N];
int key_[N],k_;
vector<int>que_[N];
pair<int,int>ans[N];
int m;
vector<int>a[N],b[N],a1[N],b1[N];

void solve(vector<int> A,vector<int> B){
	if (!A.size()||!B.size())return;
	k=1;
	int mx=A.size();
	a[1]=A;b[1]=B;
	bool yes=1;
	for(;yes;){
		fo(i,1,n)dis[i]=0;
		yes=0;
		fo(i,1,k)
		if (a[i].size()>1){
			yes=1;
			int mid=a[i].size()/2;
			fo(j,0,mid-1)dis[a[i][j]]=1;
		}
		if (yes){
			query();
			k_=0;
			fo(i,1,k)
			if (a[i].size()>1){
				a1[++k_].clear();
				int mid=a[i].size()/2;
				fo(j,0,mid-1)a1[k_].push_back(a[i][j]);
				b1[k_].clear();
				for(auto x:b[i])if (can[x])b1[k_].push_back(x);
				a1[++k_].clear();
				fo(j,mid,a[i].size()-1)a1[k_].push_back(a[i][j]);
				b1[k_].clear();
				for(auto x:b[i])if (!can[x])b1[k_].push_back(x);
			}
			else{
				a1[++k_]=a[i];
				b1[k_]=b[i];
			}
		k=k_;
		fo(i,1,k)a[i]=a1[i],b[i]=b1[i];
		}
	}
	fo(i,1,k){
		int x=a[i][0];
		for(auto y:b[i])ans[++m]=make_pair(x,y);
	}
}

int main(){
//	freopen("data.in","r",stdin);
	n=get();
	key[k=1]=0;
	pt[0].push_back(1);
	fo(i,2,n)que[1].push_back(i);
	int L=1;
	fo(i,2,n)d[i]=-1;
	for(;L*2<=n-1;L<<=1);
	for(;L>=1;L>>=1){
		fo(i,1,n)dis[i]=0;
		for(int i=1;i<=k;i+=2)
			for(auto x:pt[key[i]])dis[x]=L-1;
		query();
		fo(i,1,n)can0[i]=can[i];
		for(int i=1;i<=k;i+=2)
			for(auto x:pt[key[i]])dis[x]=L;
		query();
		fo(i,1,k){
			key_[i*2-1]=key[i];
			key_[i*2]=key[i]+L;
		}
		fo(i,1,k*2)que_[i].clear();
		bool yes=0;
		for(int i=1;i<=k;i+=2){
			for(auto x:que[i]){
				if (can0[x])que_[i*2-1].push_back(x);
				if (!can[x])que_[i*2].push_back(x);
			}
			for(auto x:que[i])
				if (can[x]&&!can0[x]){
					yes|=(i==k);
					d[x]=key[i]+L;
					pt[d[x]].push_back(x);
				}
		}
		fo(i,1,n)dis[i]=0;
		for(int i=2;i<=k;i+=2)
			for(auto x:pt[key[i]])dis[x]=L-1;
		query();
		fo(i,1,n)can0[i]=can[i];
		for(int i=2;i<=k;i+=2)
			for(auto x:pt[key[i]])dis[x]++;
		query();
		for(int i=2;i<=k;i+=2){
			for(auto x:que[i]){
				if (can0[x])que_[i*2-1].push_back(x);
				if (!can[x])que_[i*2].push_back(x);
			}
			for(auto x:que[i])
				if(can[x]&&!can0[x]){
					yes|=(i==k);
					d[x]=key[i]+L;
					pt[d[x]].push_back(x);
				}
		}
		k_=k*2-(!yes);
		k=k_;
		fo(i,1,k)key[i]=key_[i],que[i]=que_[i];
		fprintf(stderr,"<%d>\n",L);
		fo(i,1,n)fprintf(stderr,"%d ",d[i]);fprintf(stderr,"\n");
		fo(i,1,k){
			fprintf(stderr,"(%d)\n",key[i]);
			for(auto x:que[i])fprintf(stderr,"%d ",x);
			fprintf(stderr,"\n");
		}
	
	}
//	fo(i,1,n)fprintf(stderr,"%d ",d[i]);fprintf(stderr,"\n");
	vector<int>A,B;
	A.clear();B.clear();
	for(int i=0;i<n;i+=3){
		for(auto x:pt[i])A.push_back(x);
		for(auto x:pt[i+1])B.push_back(x);
	}
	solve(A,B);
	A.clear();B.clear();
	for(int i=1;i<n;i+=3){
		for(auto x:pt[i])A.push_back(x);
		for(auto x:pt[i+1])B.push_back(x);
	}
	solve(A,B);
	A.clear();B.clear();
	for(int i=2;i<n;i+=3){
		for(auto x:pt[i])A.push_back(x);
		for(auto x:pt[i+1])B.push_back(x);
	}
	solve(A,B);
	printf("!\n");
	fo(i,1,n-1)printf("%d %d\n",ans[i].first,ans[i].second);
	fflush(stdout);
	return 0;
}