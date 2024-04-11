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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	set<int> A, B, C;
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		if (A.find(x+1) != A.end()) B.insert(x);
		if (A.find(x-1) != A.end()) C.insert(x);
		A.insert(x);
	}
	int S = n*3-2;
	S -= A.size() + B.size() + C.size();
	cout << S << endl;
	return 0;
}