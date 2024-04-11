#include<bits/stdc++.h>

using namespace std;

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

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;
const db eps = 1e-15;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout<<fixed<<setprecision(15);
	ll n , m;
	cin>>n>>m;
	cout<<"? "<<2 * n + 1<<endl;
	cout<<"0 "<<m<<endl;
	cout<<"0 0"<<endl;
	for(ll i = 1 ; i < n ; i++){
		cout<<i<<' '<<(db)(m - eps)<<endl;
		cout<<i<<" 0"<<endl;
	}
	cout<<n<<' '<<m<<endl;
	db h , x , y;
	cin>>h;
	y = (h - (0.5 / (db)m)) / (1 / (db)m);
	cout<<"? "<<2 * m + 1<<endl;
	cout<<n<<" 0"<<endl;
	cout<<"0 0"<<endl;
	for(ll j = 1 ; j < m ; j++){
		cout<<(db)(n - eps)<<' '<<j<<endl;
		cout<<"0 "<<j<<endl;
	}
	cout<<n<<' '<<m<<endl;
	cin>>h;
	x = (h - (0.5 / (db)n)) / (1 / (db)n);
	cout<<"! "<<x<<' '<<y<<endl;
	return 0;
}