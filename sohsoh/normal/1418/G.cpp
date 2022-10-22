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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN] = {0}, R[MAXN], hsh_help[MAXN] = {0}, cnt[MAXN] = {0}, hsh_arr[MAXN];
map<ll, ll> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll hsh = 0;
	mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

	for (int i = 0; i < MAXN; i++) R[i] = rnd();
		
	ll ind = 0, ans = 0, n;
	cin >> n;
	mp.insert({0, 1});
	hsh_arr[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		cnt[A[i]]++;
		hsh_help[A[i]]++;
		hsh += R[A[i]];
		if (hsh_help[A[i]] >= 3) hsh_help[A[i]] = 0, hsh -= 3 * R[A[i]];
		hsh_arr[i + 1] = hsh;
		while (cnt[A[i]] > 3) {
			cnt[A[ind]]--;
			mp[hsh_arr[ind]]--;
			ind++;
		}	
		
		if (mp.find(hsh) == mp.end()) mp.insert({hsh, 0});
		ans += mp[hsh];
		mp[hsh]++;
	}	
	
	// mammad
	cout << ans << endl;
	return 0;
}