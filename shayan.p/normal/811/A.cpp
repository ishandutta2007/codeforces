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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=1e6+10;

int main(){
	ll a,b;cin>>a>>b;
	ll h=1;
	while(a>=0&&b>=0){
		a-=(2*h)-1;
		b-=(2*h);
		h++;
	}
	if(a<0){
		cout<<"Vladik\n";
	}
	else{
		cout<<"Valera\n";
	}
}