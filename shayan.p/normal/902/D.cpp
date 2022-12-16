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

int main(){
	ll n;cin>>n;
	deque<ll>d[2];
	d[0].PF(1);
	d[1].PF(1);d[1].PF(0);
	deque<ll>help;
	REP(i,n-1){
		help=d[1];
		d[1].PF(0);
		REP(j,sz(d[0])){
			d[1][j]=(d[0][j]+d[1][j])%2;
		}
		d[0]=help;
	}
	cout<<sz(d[1])-1<<endl;
	REP(i,sz(d[1]))
		cout<<d[1][i]<<" ";
	cout<<endl<<sz(d[0])-1<<endl;
	REP(i,sz(d[0]))
		cout<<d[0][i]<<" ";
}