#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll cnt = 0;
	for(ll j = 2 ; cnt < 25 ; j++){
		for(ll i = 1 ; i < j && cnt < 25 ; i++){
			cout<<"? "<<i<<' '<<j<<endl;
			ll a , b;
			cin>>a;
			if(a == -1){
				cout<<"! "<<j - 1<<endl;
				return 0;
			}
			cout<<"? "<<j<<' '<<i<<endl;
			cin>>b;
			if(a != b){
				cout<<"! "<<a + b<<endl;
				return 0;
			}
			cnt++;
		}
	}
	if(cnt == 25){
		while(true){
			cnt += rng();
		}
	}
	return 0;
}