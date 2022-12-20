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
const ll maxn=200;
ll a[maxn],b[maxn],n,k;
bool check(){
	FOR(i,1,n-1){
		if(a[i-1]>a[i])
			return 0;
	}
	return 1;
}

int main(){
	cin>>n>>k;
	REP(i,n){
		cin>>a[i];
	}
	REP(i,k){
		cin>>b[i];
	}
	if(k>1){
		cout<<"Yes";
		return 0;
	}
	REP(i,n){
		if(a[i]==0){
			a[i]=b[0];
		}
	}
	if(check()){
		cout<<"No";
	}
	else{
		cout<<"Yes";
	}
}