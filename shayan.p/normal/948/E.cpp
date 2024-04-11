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
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll sms[maxn],smt[maxn];
ll lsts[maxn],lstt[maxn];

int main(){
	string s,t;cin>>s>>t;
	FOR(i,1,sz(s)){
		lsts[i]=lsts[i-1];
		if(s[i-1]=='B'||s[i-1]=='C')
			lsts[i]=i;
		sms[i]=sms[i-1]+(s[i-1]=='B'||s[i-1]=='C');
	}
	FOR(i,1,sz(t)){
		lstt[i]=lstt[i-1];
		if(t[i-1]=='B'||t[i-1]=='C')
			lstt[i]=i;
		smt[i]=smt[i-1]+(t[i-1]=='B'||t[i-1]=='C');
	}
	ll q;cin>>q;
	string ans;
	while(q--){
		ll a,b,c,d;cin>>a>>b>>c>>d;
		ll ones=sms[b]-sms[a-1],onet=smt[d]-smt[c-1];
		ll zeros=b-max(lsts[b],a-1),zerot=d-max(lstt[d],c-1);
		if(ones>onet||(ones%2)!=(onet%2)||zeros<zerot){
			ans+="0";
			continue;
		}
		if(ones==onet && (zeros%3)!=(zerot%3)){
			ans+="0";
			continue;
		}
		if(zeros==zerot && zeros==b-a+1 && onet>0){
			ans+="0";
			continue;
		}
		ans+="1";
	}
	cout<<ans;
}