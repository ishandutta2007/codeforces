#include<bits/stdc++.h>
#define	PB push_back
#define MP make_pair
#define F first
#define S second
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define all(c) (c).begin(), (c).end()
#define sz(c) (c).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<ll,pll> pl3;

const ll inf=1e18;
const ll maxn=2e5+10;

int main(){
	ll n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	vector<ll>ans;
	REP(i,n)
		ans.PB(i);
	REP(i,m-n+1){
		vector<ll>v;
		v.clear();
		REP(j,n){
			if(t[i+j]!=s[j])
				v.PB(j);
		}
		if(sz(ans)>sz(v))ans=v;
	}
	cout<<sz(ans)<<endl;
	for(ll i=0;i<sz(ans);i++)
		cout<<ans[i]+1<<" ";
}