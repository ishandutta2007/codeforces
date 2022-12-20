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
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

priority_queue<ll> v1;
priority_queue<ll,vector<ll>,greater<ll> >v2;
ll S1,S2;

int main(){
    ll n,s;cin>>n>>s;
    REP(i,n){
	ll x;cin>>x;
	if(x<s){
	    v1.push(x);
	    S1++;
	}
	if(x>s){
	    v2.push(x);
	    S2++;
	}
    }
    
    ll ans=0;
    while(S1>(n/2)){
	ans+=s-v1.top();
	v1.pop();
	S1--;
    }
    while(S2>(n/2)){
	ans+=v2.top()-s;
	v2.pop();
	S2--;
    }
    cout<<ans;
}