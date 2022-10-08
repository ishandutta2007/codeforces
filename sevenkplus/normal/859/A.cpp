#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n, ma;

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		ma = max(ma, x);
	}
	if (ma <= 25) puts ("0");
	else cout << ma-25 << endl;
	return 0;
}