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
const ll mod=1e9+7;
const ll maxn=52;

string str[maxn];

string name(ll num){
	string s="Z";
	while(num>0){
		s+=(num%2?"a":"b");
		num/=2;
	}
	return s;
}

ll ind=1;
string ans[maxn];

int main(){
	ll n,k;cin>>n>>k;
	ll now=1;
	ans[0]=name(0);
	REP(i,n-k+1){
		cin>>str[i];
		if(str[i]=="NO"){
			if(ind<i+1){
				while(ind==i+1)
					ans[ind++]=name(now++);
			}
			ans[ind++]=ans[i];
		}
		else{
			while(ind<i+k){
				ans[ind++]=name(now++);
			}
		}
	}
	while(ind<n)
		ans[ind++]=name(now++);
	REP(i,n)
		cout<<ans[i]<<" ";
}