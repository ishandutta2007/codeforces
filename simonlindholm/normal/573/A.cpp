#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N, b = -1;
	cin >> N;
	rep(i,0,N) {
		int a;
		cin >> a;
		while (a % 2 == 0) a /= 2;
		while (a % 3 == 0) a /= 3;
		if (b == -1) b = a;
		else if (b != a) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}