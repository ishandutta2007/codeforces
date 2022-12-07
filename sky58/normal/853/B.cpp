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
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<int,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint mi[114514];
lint dp[1141818],d2[1141919];
vector<tint> co,ar;
int main()
{
	lint inf=1145141919810LL,now,out=inf;
	int d,f,c,t,n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	rep(i,m){
		scanf("%d %d %d %d",&d,&f,&t,&c);
		if(t==0) co.pb(mp(d,mp(f,c)));
		else ar.pb(mp(d,mp(t,c)));
	}
	sort(All(co));sort(All(ar));reverse(All(ar));
	rep(i,1141910) dp[i]=d2[i]=inf;
	
	rep(i,n+10) mi[i]=inf;
	now=0;REP(i,1,n+1) now+=mi[i];
	rep(i,co.size()){
		pint p=co[i].se;
		if(p.se<mi[p.fi]){
			now+=p.se-mi[p.fi];
			mi[p.fi]=p.se;
		}
		dp[co[i].fi]=min(dp[co[i].fi],now);
	}
	rep(i,1140000) dp[i+1]=min(dp[i],dp[i+1]);
	
	rep(i,n+10) mi[i]=inf;
	now=0;REP(i,1,n+1) now+=mi[i];
	rep(i,ar.size()){
		pint p=ar[i].se;
		if(p.se<mi[p.fi]){
			now+=p.se-mi[p.fi];
			mi[p.fi]=p.se;
		}
		d2[ar[i].fi]=min(d2[ar[i].fi],now);
	}
	for(int i=1140000;i>0;i--) d2[i-1]=min(d2[i],d2[i-1]);
	//rep(i,19) cout<<i<<' '<<dp[i]<<' '<<d2[i]<<endl;
	
	rep(i,1001001){
		if(i+k>1131919) continue;
		out=min(out,dp[i]+d2[i+k+1]);
	}
	if(out>=inf) cout<<-1<<endl;else cout<<out<<endl;
}