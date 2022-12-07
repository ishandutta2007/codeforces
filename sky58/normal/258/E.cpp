#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 131072
int f[N*4+10],cnt[N*4+10],ans[N],in[N],out[N];
vector <int> gr[N],com[N];
int step=0;
void dfs(int now,int pre){
	//cout<<now<<' '<<pre<<endl;
	in[now]=step;step++;
	int i;
	rep(i,gr[now].size()){
		if(gr[now][i]!=pre) dfs(gr[now][i],now);
	}
	out[now]=step;
	return;
}
void add(int a,int b,int k,int l,int r,int v){
	if(a==l && b==r) f[k]+=v;
	else{
		int m=(l+r)/2;
		if(a<m) add(a,min(b,m),k*2+1,l,m,v);
		if(m<b) add(max(a,m),b,k*2+2,m,r,v);
	}
	if(f[k]>0) cnt[k]=r-l;else cnt[k]=cnt[k*2+1]+cnt[k*2+2];
	return;
}
void dfs2(int now,int pre){
	int i;
	//cout<<now<<' '<<cnt[0]<<endl;
	rep(i,com[now].size()) add(in[com[now][i]],out[com[now][i]],0,0,N,1);
	ans[now]=cnt[0];
	rep(i,gr[now].size()){
		if(gr[now][i]!=pre) dfs2(gr[now][i],now);
	}
	rep(i,com[now].size()) add(in[com[now][i]],out[com[now][i]],0,0,N,-1);
	return;
}
int main()
{
	int i,n,m,a,b,j;
	cin>>n>>m;
	rep(i,n-1){
		scanf("%d %d",&a,&b);
		//cin>>a>>b;
		a--;b--;gr[a].pb(b);gr[b].pb(a);
	}
	dfs(0,-1);
	//rep(i,n) cout<<in[i]<<' '<<out[i]<<endl;
	memset(f,0,sizeof(f));memset(cnt,0,sizeof(cnt));
	rep(i,m){
		scanf("%d %d",&a,&b);
		//cin>>a>>b;
		a--;b--;
		if(in[a]>in[b]) swap(a,b);
		if(out[a]>=out[b]) com[a].pb(a);
		else{
			com[a].pb(a);com[a].pb(b);com[b].pb(a);com[b].pb(b);
		}
	}
	rep(i,n){
		//cout<<i;rep(j,com[i].size()) cout<<' '<<com[i][j];cout<<endl;
	}
	dfs2(0,-1);
	rep(i,n){
		printf("%d",max(0,ans[i]-1));
		if(i<n-1) printf(" ");else printf("\n");
	}
	return 0;
}