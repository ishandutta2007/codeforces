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
pint dp[2100][2100];
string s[2100];
string t;
vector <int> aru[2100][30];
int next[2100][30];
int i1[2100],sum[2100],len[2100];
int nex[1000010][30];
int inf=10000000;
pint minp(pint a,pint b){
	if(a.fi<b.fi) return a;
	if(a.fi>b.fi) return b;
	if(a.se<b.se) return a;return b;
}
int main()
{
	int i,n,m,j,k;sum[0]=0;
	cin>>n;
	rep(i,n){
		cin>>s[i];len[i]=s[i].size();
		sum[i+1]=sum[i]+len[i];
		rep(j,len[i]){
			aru[i][(s[i][j]-'a')].pb(j);
		}
		rep(j,26) nex[sum[i+1]-1][j]=inf;nex[sum[i+1]-1][(s[i][len[i]-1]-'a')]=len[i]-1;
		for(j=len[i]-2;j>=0;j--) rep(k,26){
			if((k+'a')==s[i][j]) nex[j+sum[i]][k]=j;else nex[j+sum[i]][k]=nex[j+1+sum[i]][k];
		}
	}
	rep(i,26) aru[n][i].pb(0);
	cin>>m;
	rep(i,m){cin>>i1[i];i1[i]--;}i1[m]=i1[m+1]=n;
	cin>>t;n=t.size();
	rep(i,26) next[m][i]=next[m+1][i]=m;
	for(i=m-1;i>=0;i--) rep(j,26){
		if(nex[sum[i1[i]]][j]<inf) next[i][j]=i;
		else next[i][j]=next[i+1][j];
	}
	rep(i,2100) rep(j,2100) dp[i][j]=mp(m,0);dp[0][0]=mp(0,0);
	rep(i,n) rep(j,i+1){
		dp[i+1][j]=minp(dp[i+1][j],dp[i][j]);
		int x=dp[i][j].fi,y=dp[i][j].se,z=t[i]-'a';
		//cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
		if(aru[i1[x]][z].size()<1 || aru[i1[x]][z][aru[i1[x]][z].size()-1]<y){
			dp[i+1][j+1]=minp(dp[i+1][j+1],mp(next[x+1][z],aru[i1[next[x+1][z]]][z][0]+1));
		}
		else{
			//vector <int> v=aru[i1[x]][z];
			dp[i+1][j+1]=minp(dp[i+1][j+1],mp(x,nex[sum[i1[x]]+y][z]+1));
		}
	}
	for(i=n;i>=0;i--){
		if(dp[n][i].fi<m){
			cout<<i<<endl;break;
		}
	}
	return 0;
}