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
lint num[110000],lcm[110000],dp[110000];
lint inf=12345678901234LL;
vector <int> gr[110000];
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
/*lint lc(lint a,lint b){
	return min(inf,a/gcd(a,b)*b);
}*/
lint pr(lint a,lint b){
	if(inf/b<a) return inf;return a*b;
}
lint dfs(int now,int pre){
	lcm[now]=1;
	rep(i,gr[now].size()){
		if(gr[now][i]==pre) continue;
		lint t=dfs(gr[now][i],now);
		//cout<<t<<' '<<lcm[now]/gcd(lcm[now],t)<<endl;
		//cout<<pr(1,1)<<endl;
		lcm[now]=pr(lcm[now]/gcd(lcm[now],t),t);
	}
	int t=gr[now].size();if(pre>=0) t--;
	if(t>1) lcm[now]=pr(lcm[now],t);
	//cout<<now<<' '<<lcm[now]<<endl;
	return lcm[now];
}
lint dfs2(int now,int pre){
	if(gr[now].size()<1 || (gr[now].size()==1 && pre>=0)) return dp[now]=num[now];
	lint mi=inf,lc2=1;
	rep(i,gr[now].size()){
		if(gr[now][i]==pre) continue;
		mi=min(mi,dfs2(gr[now][i],now));
		lc2=pr(lc2,lcm[gr[now][i]]/gcd(lc2,lcm[gr[now][i]]));
	}
	int t=gr[now].size();if(pre>=0) t--;
	dp[now]=((mi/lc2)*lc2)*t;
	//cout<<now<<' '<<dp[now]<<endl;
	return dp[now];
}
int main()
{
	int n,a,b;lint sum=0;cin>>n;
	rep(i,n){
		cin>>num[i];sum+=num[i];
	}
	rep(i,n-1){
		cin>>a>>b;a--;b--;gr[a].pb(b);gr[b].pb(a);
	}
	dfs(0,-1);cout<<sum-dfs2(0,-1)<<endl;
	return 0;
}