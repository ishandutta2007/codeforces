/*
    Soheil Mohammadkhani
    OK, im back :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	fast_io;
	ll cnt[15] = {0};
	for (int i = 0; i < 6; i++) {
		ll x;
		cin >> x;
		cnt[x]++;
	}

	bool can = false;
	for (int i = 0; i < 15; i++) if (cnt[i] > 3) cnt[i] -= 4, can = true;
	if (!can) return cout << "Alien" << endl, 0;
	can = false;
	for (int i = 0; i < 15; i++) if (cnt[i] > 1) can = true;
       	if (can) cout << "Elephant" << endl;
	else cout << "Bear" << endl;	
}