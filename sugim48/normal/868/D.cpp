#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<double, int> d_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 10;
const int MOD = 1e9 + 7;

void f(string s, set<string>& st) {
	int N = s.length();
	for (int l = 0; l <= N; l++)
		for (int r = l + 1; r <= N; r++)
			if (r - l <= 20)
				st.insert(s.substr(l, r - l));
}

int main() {
	int N; cin >> N;
	vector<string> a(N);
	rep(i, N) cin >> a[i];
	vector<set<string> > st(N);
	rep(i, N) f(a[i], st[i]);
	int Q; cin >> Q;
	while (Q--) {
		int i1, i2; cin >> i1 >> i2;
		i1--, i2--;
		string s = a[i1] + a[i2];
		set<string> S;
		for (string s: st[i1]) S.insert(s);
		for (string s: st[i2]) S.insert(s);
		f(s, S);
		if (s.length() > 40) {
			string pre = s.substr(0, 20);
			string suf = s.substr(s.length() - 20);
			s = pre + "#" + suf;
		}
		a.pb(s), st.pb(S);
		int k;
		for (k = 1; ; k++) {
			bool ok = true;
			rep(T, 1<<k) {
				string t(k, ' ');
				rep(j, k) t[j] = "01"[T>>j & 1];
				if (!S.count(t)) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				k--;
				break;
			}
		}
		cout << k << endl;
	}
}