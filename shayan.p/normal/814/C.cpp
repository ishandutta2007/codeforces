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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=1600;

string s;
ll sum[maxn];
ll ans[30][maxn];
ll n;

void make_arr(char ch){
	sum[0]=0;
	FOR(i,1,n){
		sum[i]=sum[i-1]+(s[i-1]==ch);
	}
}
void pre(ll id){
	FOR(i,1,n){
		FOR(j,i,n){
			ll num=j-i+1-(sum[j]-sum[i-1]);
			ans[id][num]=max(j-i+1,ans[id][num]);
		}
	}
	FOR(i,1,n){
		ans[id][i]=max(ans[id][i],ans[id][i-1]);
	}
}
int main(){
	cin>>n>>s;
	FOR(i,'a','z'){
		make_arr(i);
		pre(i-'a');
	}
	ll q;cin>>q;
	REP(i,q){
		ll m;char ch;
		cin>>m>>ch;
		m=min(m,n);
		cout<<ans[ch-'a'][m]<<endl;
	}
}