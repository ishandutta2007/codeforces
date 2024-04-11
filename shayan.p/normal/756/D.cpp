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
const ll maxn=5010;
const ll mod=1e9+7;

ll dp[30][maxn],tot[maxn],sm[maxn];

int main(){
    ll n;cin>>n;
    string s;cin>>s;
    FOR(i,1,n){
	ll c=s[i-1]-'a';
	FOR(j,1,n){
	    sm[j]=(sm[j-1]+tot[j]-dp[c][j]+mod)%mod;
	}
	FOR(j,1,n){
	    tot[j]=tot[j]+mod-dp[c][j];
	    dp[c][j]=(sm[j-1]+1)%mod;
	    tot[j]=(tot[j]+dp[c][j])%mod;
	}
    }
    cout<<tot[n];
}