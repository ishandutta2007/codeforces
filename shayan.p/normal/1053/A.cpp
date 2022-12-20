// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ll n,m,k;cin>>n>>m>>k;
    if(gcd(m,k)==1){
	n*=2;
	ll x=gcd(n,k);
	n/=x;
	k/=x;
	x=gcd(m,k);
	m/=x;
	k/=x;
    }
    else{
	m*=2;
	ll x=gcd(m,k);
	m/=x;
	k/=x;
	x=gcd(n,k);
	n/=x;
	k/=x;
    }
    
    
    if(k!=1){
	cout<<"NO\n";
	return 0;
    }
    
    cout<<"YES\n";
    cout<<0<<" "<<0<<endl;
    cout<<n<<" "<<0<<endl;
    cout<<0<<" "<<m<<endl;
}