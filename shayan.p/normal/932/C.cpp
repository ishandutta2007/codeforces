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

#define bug(i) cerr<<i<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

void print(ll start,ll len){
	FOR(i,start+1,start+len-1)
		cout<<i<<" ";
	cout<<start<<" ";
}

int main(){
	ll n,a,b;cin>>n>>a>>b;
	ll numa=0,numb=-1;
	while(n>=(a*numa)){
		if((n-(a*numa))%b==0){
			numb=(n-(a*numa))/b;
			break;
		}
		numa++;
	}
	if(numb==-1){
		cout<<-1;
		return 0;
	}
	ll beg=1;
	REP(i,numa){
		print(beg,a);
		beg+=a;
	}
	REP(i,numb){
		print(beg,b);
		beg+=b;
	}
}