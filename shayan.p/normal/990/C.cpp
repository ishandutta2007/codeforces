// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

map<ll,ll>pos,neg;
ll zero;

int main(){
	ll n;cin>>n;
	REP(i,n){
		string s;cin>>s;
		ll num=0,mn=0;
		REP(j,sz(s)){
			num+=((s[j]=='(')?(1):(-1));
			mn=min(mn,num);
		}
		if(num==0&&mn==0)
			zero++;
		if(num<0&&mn==num)
			neg[num]++;
		if(num>0&&mn>=0)
			pos[num]++;
	}
	ll ans=(zero*zero);
	for(map<ll,ll>::iterator it=pos.begin();it!=pos.end();it++){
		ans+=pos[(it->F)]*neg[-(it->F)];
	}
	cout<<ans;
}