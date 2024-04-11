#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int main() {
	bitset<100> A;
	for (int i = 0; i < 100; i++) A[i] = 1;
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		bitset<100> B;
		while (n--) {
			int x;
			cin >> x;
			B[x-1] = 1;
		}
		A &= B;
	}
	vector<int> S;
	for (int i = 0; i < 100; i ++)
		if (A[i]) S.pb(i+1);
	for (int i = 0; i < (int) S.size(); i ++)
		printf("%d%c", S[i], i == (int) S.size()-1?'\n':' ');
	return 0;
}