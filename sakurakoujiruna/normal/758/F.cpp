#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;

const int N = 1e7L + 11;
int f[N], p[N];

int main() {
	int n, l, r; cin >> n >> l >> r;
	if(n == 1) {
		cout << r - l + 1 << '\n';
		return 0;
	}
	n --;
	for(int i = 1; i < N; i ++) {
		ll t = 1;
		for(int j = 0; j < n; j ++) {
			t *= i;
			if(t >= N) t = N;
		}
		if(t >= N) break;
		f[t] = 1;
	}
	for(int i = 1; i < N; i ++)
		f[i] += f[i - 1];
	for(int i = 2; i < N; i ++) if(!p[i])
		for(int j = i; j < N; j += i) if(!p[j]) p[j] = i;
	
	ll ans = 0;
	for(int i = l; i <= r; i ++) {
		vector <int> v;
		for(int j = i; j > 1; j /= p[j]) v.pb(p[j]);
		int d = 1, cnt = 0;
		for(int j = 0; j < v.size(); j ++) {
			cnt ++;
			if(j + 1 == v.size() || v[j] != v[j + 1]) {
				for(int k = 0; k < cnt / n; k ++)
					d *= v[j];
				cnt = 0;
			}
		}
		int dn = 1;
		if(d != 1) for(int j = 0; j < n; j ++) dn *= d;
		int idn = i / dn, s = (l + idn - 1) / idn;
		int e = 1;
		if(d != 1) for(int j = 0; j < n; j ++) {
			e *= d;
			if(e >= N) {
				e = N;
				break;
			}
		}
		ans += f[e - 1] - f[s - 1];
	}
	cout << ans * 2 << '\n';
	
}