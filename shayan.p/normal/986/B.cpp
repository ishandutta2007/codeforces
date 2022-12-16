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
const ll maxn=1e6+10;
const ll mod=1e9+7;

bool is[maxn];
ll a[maxn];

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    ll ans=0;
    FOR(i,1,n){
	ans+=(!is[i]);
	ll x=i;
	while(!is[x]){
	    is[x]=1;
	    x=a[x];
	}
    }
    if(ans%2==0)
	cout<<"Petr";
    else
	cout<<"Um_nik";
}