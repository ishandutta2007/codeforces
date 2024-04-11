//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 100000;

int read() { int x; cin >> x; return x; }

map<string, int> mark;
string q[N];
int h, t;

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string source = "", sink = "", tmp;
	cin >> tmp; source += tmp;
	cin >> tmp; source += tmp;
	cin >> tmp; sink += tmp;
	cin >> tmp; sink += tmp;
	mark[source] = 1;
	q[t++] = source;
	while (h != t) {
		string cur = q[h++];
		for (int pos = 0; pos < 4; ++pos) if (cur[pos] == 'X') {
			int a = 0, b = 0;
			if (pos == 0) {
				a = 1;
				b = 2;
			} else if (pos == 1) {
				a = 0;
				b = 3;
			} else if (pos == 2) {
				a = 0;
				b = 3;
			} else {
				a = 2;
				b = 1;
			}
			string s = cur;
			swap(s[a], s[pos]);
			if (!mark[s]++)
				q[t++] = s;
			swap(s[a], s[pos]);
			swap(s[b], s[pos]);
			if (!mark[s]++)
				q[t++] = s;
		}
	}
	if (mark[sink]) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}