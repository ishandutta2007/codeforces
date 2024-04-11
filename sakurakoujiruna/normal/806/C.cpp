#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 1e5L + 11;
ll a[N];

int cnt[50];

bool check(int n, int m) {
	memset(cnt, 0, sizeof cnt);
	cnt[0] = m; vector <ll> v;
	for(int i = 0; i < n; i ++) {
		int b = 63 - __builtin_clzll(a[i]);
		if((1LL << b) == a[i] && cnt[b]) {
			cnt[b] --;
			cnt[b + 1] ++;
		} else
			v.pb(a[i]);
	}
	reverse(v.begin(), v.end());
	for(int i = 1; i < 50; i ++)
		while(cnt[i] --) {
			ll lim = 1LL << i;
			if(v.size() && v.back() <= lim)
				v.pop_back();
		}
	return v.size() == 0;
}

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a, a + n);
	
	int lim = count(a, a + n, 1);
	if(check(n, lim)) {
		int l = 1, r = lim + 1;
		while(l + 1 < r) {
			int m = (l + r) / 2;
			if(check(n, m - 1))
				r = m;
			else
				l = m;
		}
		for(int i = l; i <= lim; i ++)
			cout << i << '\n';
	} else
		cout << "-1\n";
	
	return 0;
}