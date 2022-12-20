// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll ans,n,s;
map<ll,ll>mp;

int main(){
    cin>>n;
    REP(i,n){
	ll x;cin>>x;
	mp[x]++;
    }
    for(map<ll,ll>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++){
	ans+=max(ll(0),(it->S)-s);
	s=(it->S)+max(ll(0),s-(it->S));
    }
    cout<<n-ans;
}