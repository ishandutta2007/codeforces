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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

set<pair<double,ll> >h;// y,x
int main(){
	ll n,r;cin>>n>>r;
	REP(i,n){
		ll x;cin>>x;
double H_mx=-1;
		pair<double,ll>p;
		for(set<pair<double,ll> >::reverse_iterator it=h.rbegin();it!=h.rend();it++){
			if((((x-r)<=(it->S+r))&&(it->S<=x))||(((it->S-r)<=(x+r))&&(x<=it->S))){

				p=*it;
double H=p.F+sqrt((4*r*r)-((p.S-x)*(p.S-x)));
H_mx=max(H_mx,H);
			}
		}
		if(H_mx==-1)
H_mx=r;
		cout<<setprecision(9)<<fixed<<H_mx<<endl;
		h.insert(MP(H_mx,x));
	}
}