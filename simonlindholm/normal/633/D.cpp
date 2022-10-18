#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> a(N);
	map<int, int> vals;
	rep(i,0,N) {
		cin >> a[i];
		++vals[a[i]];
	}
	int z = 0;
	rep(i,0,N) if (a[i] == 0) z++;

	int res = z;
	rep(i0,0,N) {
		rep(i1,0,N) {
			if (i0 == i1) continue;
			int a0 = a[i0];
			int a1 = a[i1];
			if (a0 == 0 && a1 == 0) continue;
			--vals[a0];
			--vals[a1];
			int len = 2;
			for (;;) {
				int c = a0 + a1;
				auto it = vals.find(c);
				if (it == vals.end() || it->second == 0) break;
				len++;
				--it->second;
				a0 = a1;
				a1 = c;
			}
			res = max(res, len);

			a0 = a[i0];
			a1 = a[i1];
			++vals[a0];
			++vals[a1];
			rep(i,0,len-2) {
				int c = a0 + a1;
				++vals[c];
				a0 = a1;
				a1 = c;
			}
		}
	}

	cout << res << endl;
}