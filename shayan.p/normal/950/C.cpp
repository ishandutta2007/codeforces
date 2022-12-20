// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<vector<ll> > ans;
ll bal;// the place where 0 starts
vector<ll> dv;

int main(){
	vector<ll>vec;
	string s;cin>>s;
	if(s[0]=='1'||s[sz(s)-1]=='1'){
		cout<<-1;
		return 0;
	}
	ll i=0;
	while(i<sz(s)){
		ll bfind=i;
		char bf=s[i];
		while(i<sz(s)&&s[i]==bf)
			i++;
		dv.PB(i-bfind);
	}
	ll po=1;
	REP(i,dv[0]){
		vec.clear();
		vec.PB(po++);
		ans.PB(vec);
	}
	for(ll i=2;i<sz(dv);i+=2){
		if(dv[i-1]>(sz(ans)-bal)){
			cout<<-1;
			return 0;
		}
		REP(j,dv[i-1])
			ans[j+bal].PB(po++);
		bal+=dv[i-1];
		ll num=dv[i]-bal;
		ll m=min(bal,dv[i]);
		REP(j,m)
			ans[--bal].PB(po++);
		if(num<=0)
			continue;
		REP(j,num){
			vec.clear();
			vec.PB(po++);
			ans.PB(vec);
		}
	}
	if(bal!=0){
		cout<<-1;
		return 0;
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans)){
		cout<<sz(ans[i])<<" ";
		REP(j,sz(ans[i]))
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}