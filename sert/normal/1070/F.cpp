#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	int n;
	cin >> n;
	vector<ll> a00, a01, a10, a11;
	for (int i = 0; i < n; i++) {
		string s;
		int val;
		cin >> s >> val;
		if (s == "00") a00.push_back(val);
		if (s == "01") a01.push_back(val);
		if (s == "10") a10.push_back(val);
		if (s == "11") a11.push_back(val);
	}

	sort(a00.rbegin(), a00.rend());
	sort(a01.rbegin(), a01.rend());
	sort(a10.rbegin(), a10.rend());
	sort(a11.rbegin(), a11.rend());

	int s00 = a00.size();
	int s01 = a01.size();
	int s10 = a10.size();
	int s11 = a11.size();

	int kk = min(s10, s01);
	ll val = 0;
	for (int i = 0; i < kk; i++) {
		val += a01[i] + a10[i];
	}
	for (int i = 0; i < s11; i++) {
		val += a11[i];
	}

	vector<ll> v;
	for (int i = kk; i < s01; i++) v.push_back(a01[i]);
	for (int i = kk; i < s10; i++) v.push_back(a10[i]);
	for (int i = 0; i < s00; i++) v.push_back(a00[i]);
	sort(v.rbegin(), v.rend());

	kk = min(s11, (int)v.size());
	for (int i = 0; i < kk; i++) {
		val += v[i];
	}

	cout << val << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 4;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}