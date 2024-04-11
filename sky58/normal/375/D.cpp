#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 101000
vector<int> gr[N];
int c[N],lo[N],hi[N],id[N],c2[N],sum[N],co[N],l[N],r[N],k[N],ret[N];
int v=0,S;
void dfs(int now,int pre){
	lo[now]=v;c2[v]=c[now];v++;
	rep(i,gr[now].size()){
		if(gr[now][i]!=pre) dfs(gr[now][i],now);
	}
	hi[now]=v;
}
bool cmp(const int i,const int j){
	if(l[i]/S==l[j]/S){
		if(((l[i]/S)&1)) return r[i]<r[j];return r[i]>r[j];
		//return r[i]<r[j];
	}
	return l[i]<l[j];
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;S=(int)sqrt(1e-8+n);
	rep(i,n) cin>>c[i];
	rep(i,n-1){
		cin>>a>>b;gr[a-1].pb(b-1);gr[b-1].pb(a-1);
	}
	dfs(0,-1);
	//rep(i,n) cerr<<c2[i]<<' ';cerr<<endl;
	rep(i,m){
		cin>>a>>k[i];a--;l[i]=lo[a];r[i]=hi[a];id[i]=i;
	}
	sort(id,id+m,cmp);int L=0,R=0;
	rep(j,m){
		int i=id[j];//cerr<<l[i]<<' '<<r[i]<<endl;
		while(L>l[i]){
			L--;sum[c2[L]]++;co[sum[c2[L]]]++;
		}
		while(R<r[i]){
			sum[c2[R]]++;co[sum[c2[R]]]++;R++;
		}
		while(L<l[i]){
			co[sum[c2[L]]]--;sum[c2[L]]--;L++;
		}
		while(R>r[i]){
			R--;co[sum[c2[R]]]--;sum[c2[R]]--;
		}
		ret[i]=co[k[i]];
	}
	rep(i,m) cout<<ret[i]<<endl;
}