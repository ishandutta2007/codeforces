#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 2000000357 , inf = 2e9 + 1;
// check problem statement

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a , b , c , d , e;
	cin>>a>>b>>c;
	d = a + b; e = c;
	d %= 2; d += 2; d %= 2; e %= 2;
	if(d != e){
		cout<<"NO\n";
		return 0;
	}
	if(c < abs(a) + abs(b)){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	return 0;
}

/*

*/