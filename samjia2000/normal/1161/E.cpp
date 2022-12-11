#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 1e5+5;

int n,a[N];
bool ans[N];
int k,cnt[N],key[N];
vector<pair<int,int> > tq;
char s[N];

void query(){
	if (!tq.size())return;
	printf("Q %d ",tq.size());
	for(auto x:tq)printf("%d %d ",x.first,x.second);
	fflush(stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	fo(i,0,len-1)ans[tq[i].first]=s[i+1]-'0';
}

int col[N];

int main(){
	int T;
	scanf("%d",&T);
	for(;T;T--){
		scanf("%d",&n);
		tq.clear();
		for(int i=1;i+1<=n;i+=2)tq.push_back(make_pair(i,i+1));
		query();
		tq.clear();
		for(int i=2;i+1<=n;i+=2)tq.push_back(make_pair(i,i+1));
		query();
		cnt[k=1]=1;
		key[1]=1;
		fo(i,2,n)
		if (ans[i-1])cnt[k]++;
		else{
			cnt[++k]=1;
			key[k]=i;
		}
		tq.clear();
		for(int i=1;i+2<=k;i+=4){
			tq.push_back(make_pair(key[i+2],key[i]));
			if (i+3<=k)tq.push_back(make_pair(key[i+3],key[i+1]));
		}
		query();
		tq.clear();
		for(int i=3;i+2<=k;i+=4){
			tq.push_back(make_pair(key[i+2],key[i]));
			if (i+3<=k)tq.push_back(make_pair(key[i+3],key[i+1]));
		}
		query();
		if (k==1){
			printf("A %d 0 0\n",n);
			fo(i,1,n)printf("%d ",i);printf("\n\n\n");
		}
		else{
			int ret[3];
			ret[0]=ret[1]=ret[2]=0;
			ret[1]=cnt[1],ret[2]=cnt[2];
			int c[3];
			c[0]=0,c[1]=1,c[2]=2;
			col[key[1]]=1;col[key[2]]=2;
			fo(i,3,k){
				if (ans[key[i]]){
					int tmp=ret[1]+cnt[i];
					ret[1]=ret[2];
					ret[2]=tmp;
					
					col[key[i]]=c[1];
					swap(c[1],c[2]);
				}
				else{
					int tmp=ret[0]+cnt[i];
					ret[0]=ret[1];
					ret[1]=ret[2];
					ret[2]=tmp;
					
					col[key[i]]=c[0];
					tmp=c[0];
					c[0]=c[1];
					c[1]=c[2];
					c[2]=tmp;
				}
			}
			printf("A %d %d %d\n",ret[0],ret[1],ret[2]);
			fo(i,1,k)if (col[key[i]]==c[0])fo(j,key[i],key[i]+cnt[i]-1)printf("%d ",j);
			printf("\n");
			fo(i,1,k)if (col[key[i]]==c[1])fo(j,key[i],key[i]+cnt[i]-1)printf("%d ",j);
			printf("\n");
			fo(i,1,k)if (col[key[i]]==c[2])fo(j,key[i],key[i]+cnt[i]-1)printf("%d ",j);
			printf("\n");
		}
		fflush(stdout);
	}
	return 0;
}