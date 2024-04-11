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
const ll maxn=2e5+10;

ll n,s;

bool realy_big(ll num){
	ll cop=num;
	ll sum=0;
	while(cop>0){
		sum+=cop%10;
		cop/=10;
	}
	if(num-sum>=s)return 1;
	else return 0;
}

int main(){
	cin>>n>>s;
	if(n<s){
		cout<<0;
		return 0;
	}
	ll num=0;
	FOR(i,s,min(n,s+300)){
//		cout<<i<<" "<<realy_big(i)<<endl;
		if(!realy_big(i)){
			num++;
		}
	}
	cout<<n-s+1-num;
}