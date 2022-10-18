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
	string S;
	cin >> S;
	if (sz(S) > 2) {
		int a = S[0] - 'A';
		int b = S[1] - 'A';
		rep(i,2,sz(S)) {
			int c = (a + b) % 26;
			int d = S[i] - 'A';
			if (c != d) {
				cout << "NO" << endl;
				return 0;
			}
			a = b;
			b = c;
		}
	}
	cout << "YES" << endl;
}