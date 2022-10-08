#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> PI3;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

set<PI3> A;
set<PII> B;

int main() {
	int n; cin >> n;
	A.insert(mp(mp(0, 0), 0));
	while (n--) {
		int t;
		cin >> t;
		set<PI3> C;
		for (set<PI3>::iterator i = A.begin(); i != A.end(); i ++) {
			int x = i->fi.fi;
			int y = i->fi.se;
			int d = i->se;
			for (int j = 1; j <= t; j ++) {
				x += dx[d];
				y += dy[d];
				B.insert(mp(x, y));
			}
			C.insert(mp(mp(x, y), (d+1)&7));
			C.insert(mp(mp(x, y), (d+7)&7));
		}
		A = C;
	}
	cout << (int) B.size() << endl;
	return 0;
}