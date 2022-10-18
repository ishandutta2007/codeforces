#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	rep(i,0,N) {
		string s;
		cin >> s;
		int mi = 10;
		rep(bi,0,(1 << 10)) {
			int goals[2]{};
			rep(j,0,10) {
				if (s[j] == '1' || (s[j] == '?' && (bi & (1 << j)))) {
					goals[j%2]++;
				}
				if (goals[0] > goals[1] + (10 - j) / 2 || goals[1] > goals[0] + (9 - j) / 2) {
					mi = min(mi, j + 1);
					break;
				}
			}
		}
		cout << mi << endl;
	}
	exit(0);
}