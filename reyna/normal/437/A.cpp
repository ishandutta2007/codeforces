//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


const int N = 4;

int read() { int x; cin >> x; return x; }

int sz[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int mx = -9999999, mn = -mx;
	for (int i = 0; i < 4; ++i) {
		string s; cin >> s;
		sz[i] = s.size() - 2;
		smax(mx, sz[i]);
		smin(mn, sz[i]);
	}
	int res = 0, id = 0;
	for (int i = 0; i < 4; ++i) {
		int fl = 0;
		if (sz[i] == mx) {
			fl = 1;
			for (int j = 0; j < 4; ++j) if (i != j)
				if (sz[i] < sz[j] * 2)
					fl = 0;
		}
		if (sz[i] == mn) {
			fl = 1;
			for (int j = 0; j < 4; ++j) if (i != j)
				if (sz[i] * 2 > sz[j])
					fl = 0;	
		}
		if (fl)
			res++, id = i;
	}
	if (res != 1)
		cout <<  'C' << endl;
	else
		cout << char(id + 'A') << endl;
	
	
	
}