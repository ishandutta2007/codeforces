#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string name() {
	string out;
	out += (char)('A' + rand() % 26);
	rep(i,0,9) out += (char)('a' + rand() % 26);
	return out;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, K;
	cin >> N >> K;
	string q;
	vector<string> res(N);
	rep(i,0,K-1) res[i] = name();
	rep(i,0,N-K+1) {
		cin >> q;
		if (q == "NO") res[i + K-1] = res[i];
		else res[i + K-1] = name();
	}
	trav(x, res) cout << x << ' ';
	cout << endl;
	exit(0);
}