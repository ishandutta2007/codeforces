#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int pr[1000000];
int head[1000000];
int next[1000000];
int e[1000000];
int ff[1000000];
int b[1000000];
int sz[1000000];
ll dp[1000000];
ll ans[1000000];

int kl;
pair<pi,pi> p[1000000];
vector<int> vv;
vector<int> rr;

int get(int v){
	if (pr[v]==v){
		return v;
	}
	return pr[v]=get(pr[v]);	
}
void unionn(int v1,int v2){
	v1=get(v1);
	v2=get(v2);
	if (pr[v1]!=pr[v2]){
		if (rand()%2==0){
			pr[v1]=v2;
			sz[v2]+=sz[v1];
		} else{
			pr[v2]=v1;
			sz[v1]+=sz[v2];
		}
	}
}
void add(int x,int y,int z){
	kl++;
	next[kl]=head[x];
	head[x]=kl;
	e[kl]=y;
	ff[kl]=z;
}
int get0(int v){
	return lower_bound(vv.begin(),vv.end(),get(v))-vv.begin();
}
void dfs(int v){
	b[v]=1;
	dp[v]=sz[vv[v]];
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0){
			dfs(e[bb]);
			dp[v]+=dp[e[bb]];
		}
	}
}
void dfs1(int v,int r){
	b[v]=1;
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0){
			dfs1(e[bb],r);
			ans[ff[bb]]=dp[e[bb]]*(dp[r]-dp[e[bb]]);
		}
	}
}
void obr(){
	//cerr<<"Start"<<endl;
	int n,m;
	sort(vv.begin(),vv.end());
	vv.resize(unique(vv.begin(),vv.end())-vv.begin());
	n=vv.size();
	m=rr.size();
	for (int i=0;i<n;i++){		
	//	cerr<<vv[i]<<" "<<sz[vv[i]]<<endl;
		head[i]=0;
		b[i]=0;
		dp[i]=0;
	}
	kl=0;
	//cerr<<"Start"<<endl;
	for (int i=0;i<m;i++){
		//cerr<<rr[i]<<endl;
		add(get0(p[rr[i]].sc.fs),get0(p[rr[i]].sc.sc),rr[i]);
		add(get0(p[rr[i]].sc.sc),get0(p[rr[i]].sc.fs),rr[i]);
	}
	for (int i=0;i<n;i++)if(b[i]==0){
		dfs(i);
	}
	for (int i=0;i<n;i++){
		b[i]=0;
	}
	for (int i=0;i<n;i++)if(b[i]==0){
		dfs1(i,i);
	}

}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    srand(312431);
    int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		scanf("%d %d %d",&p[i].sc.fs,&p[i].sc.sc,&p[i].fs.fs);
		p[i].sc.fs--;
		p[i].sc.sc--;
		p[i].fs.sc=i+1;
	}
	sort(p,p+n-1);
	for (int i=0;i<n;i++){
		sz[i]=1;
		pr[i]=i;
	}
	int pr0=-1;
	for (int i=0;i<n-1;i++){
		if (i==n-2 || p[i+1].fs.fs!=p[i].fs.fs){
			vv.clear();
			rr.clear();
			for (int j=pr0+1;j<=i;j++){
				vv.pb(get(p[j].sc.fs));
				vv.pb(get(p[j].sc.sc));
				rr.pb(j);
			}
			obr();
			for (int j=pr0+1;j<=i;j++){
				unionn(p[j].sc.fs,p[j].sc.sc);
			}
			pr0=i;
		} 
	}
	vv.clear();
	ll mx=0;
	for (int i=0;i<n-1;i++){
		if (ans[i]>mx){
			mx=ans[i];
			vv.clear();
		}
		if (ans[i]==mx){
			vv.pb(p[i].fs.sc);
		}
	}
	sort(vv.begin(),vv.end());
	cout<<mx*2<<" "<<vv.size()<<endl;
	for (int i=0;i<(int)vv.size();i++){
		printf("%d ",vv[i]);
	}
	printf("\n");
    return 0;
}