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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[50010][510];
int depth[50010];
bool sumi[50010];
int n,k;
vector <vector <int> > gr;vector <int> cl;
void dfs(int a,int b){
	int i,j;
	sumi[a]=true;depth[a]=b;dp[a][0]=1;
	rep(i,gr[a].size()){
		int nex=gr[a][i];
		if(!sumi[nex]){
			dfs(nex,b+1);
			rep(j,k) dp[a][j+1]+=dp[nex][j];
		}
	}
	return;
}
int main()
{
	int i,j,a,b;lint out=0;
	rep(i,50010) rep(j,510) dp[i][j]=0;
	cin>>n>>k;
	rep(i,n+10) gr.pb(cl);
	rep(i,n-1){
		scanf("%d %d",&a,&b);gr[a].pb(b);gr[b].pb(a);
	}
	memset(sumi,false,sizeof(sumi));
	dfs(1,0);
	rep(i,n){
//		rep(j,k+1) cout<<dp[i+1][j]<<' ';cout<<endl;
	}
	REP(i,1,n+1){
		rep(j,k+1) out+=dp[i][j]*dp[i][k-j];
		if(i>1){
			rep(j,k-1) out-=dp[i][j]*dp[i][k-2-j];
		}
	}
	cout<<out/2<<endl;
	return 0;
}