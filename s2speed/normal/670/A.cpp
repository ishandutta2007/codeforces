#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n; q = n - 2;
	if(n == 1){
		cout<<"0 1\n";
		return 0;
	}
	ll h = (q / 7) * 5 + min(q % 7 , 5ll) , o;
	o = (n / 7) * 5 + min(n % 7 , 5ll);
	cout<<n - o<<' '<<n - h<<'\n';
	return 0;
}

/*

*/