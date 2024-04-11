#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll inf=1e18;
int main(){
	ll N,M,Mina=inf,Minb=inf;cin>>N>>M;
	set<ll>a,b,m;
	for(ll i=0;i<N;i++){
		ll x;cin>>x;a.insert(x);
		Mina=min(Mina,x);
	}
	for(ll i=0;i<M;i++){
		ll x;cin>>x;b.insert(x);
		if(a.count(x))m.insert(x);
		Minb=min(Minb,x);
	}
	if(m.size())cout<<*m.begin();
	else cout<<min(Mina,Minb)<<max(Mina,Minb);
}