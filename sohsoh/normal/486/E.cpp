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

set<pll> st[MAXN];
ll A[MAXN] = {0}, lis[MAXN] = {0}, n;

set<ll> is_ans[MAXN], is_ans_ind[MAXN];

int main() {
	fast_io;
	cin >> n;
	st[0].insert({-1, -1});
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		ll L = 0;
		ll R = n;
		while (L < R) {
			ll mid = (L + R + 1) / 2;
			auto it = st[mid].lower_bound({A[i], -1});
			if (it != st[mid].begin()) L = mid;
			else R = mid - 1;
		}

		lis[i] = L + 1;
		st[lis[i]].insert({A[i], i});
	}
	
	ll ans = *max_element(lis, lis + n);
	for (int i = n - 1; i >= 0; i--) {
		if (lis[i] == ans) {
			is_ans[ans].insert(A[i]);
			is_ans_ind[ans].insert(i);
			continue;
		}

		ll x = lis[i];
		auto it = is_ans[x + 1].upper_bound(A[i]);
		if (it == is_ans[x + 1].end()) continue;
		is_ans[x].insert(A[i]);
		is_ans_ind[x].insert(i);
	}

	for (int i = 0; i < n; i++) {
		ll x = lis[i];
		if (is_ans_ind[x].find(i) == is_ans_ind[x].end()) cout << 1;
		else {
			if (is_ans_ind[x].size() == 1) cout << 3;
			else cout << 2;
		}
	}	

	cout << endl;
	return 0;
}