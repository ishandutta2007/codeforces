#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, k, x;
	cin >> n >> k >> x;

	vector <ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));

	vector<ll> merge_val;

	for (int i = 1; i < n; ++i) {
		ll now = a[i], pr = a[i - 1];
		if (now - pr <= x) continue;
		ll y = (now - pr - 1) / x;
		merge_val.pb(y);
	}
	sort(all(merge_val));

	ll sum = 0;
	for (int i = 0; i < (int) merge_val.size(); ++i) {
		if (sum + merge_val[i] > k) {
			cout << merge_val.size() - i + 1 << "\n";
			return 0;
		}
		sum += merge_val[i];
	}
	cout << "1\n";
}