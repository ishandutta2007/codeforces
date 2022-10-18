#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	string str;
	cin >> str;
	int sum = 0;
	for (char ch : str) {
		if ('a' <= ch && ch <= 'z')
			sum -= ch - 'a' + 1;
		if ('A' <= ch && ch <= 'Z')
			sum += ch - 'A' + 1;
	}
	cout << sum << endl;
}