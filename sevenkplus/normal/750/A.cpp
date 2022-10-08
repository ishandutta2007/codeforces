#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int n, t;
	cin >> n >> t;
	t = 240 - t;
	int S = 0;
	for (int i = 1; i <= n; i ++) {
		if (t >= 5*i) {
			S++;
			t -= 5*i;
		}
	}
	cout << S << endl;
	return 0;
}