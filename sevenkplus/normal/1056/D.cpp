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

#define N 100100
int n;
int p[N], s[N];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	p[0] = -1;
	for (int i = 1; i < n; i ++) {
		int x; cin >> x; x--;
		p[i] = x;
	}
	for (int i = n-1; i >= 0; i--) {
		if (!s[i]) s[i] ++;
		if (p[i] != -1) s[p[i]] += s[i];
	}
	sort(s, s+n);
	for (int i = 0; i < n; i ++)
		cout << s[i] << (i == n-1?'\n':' ');
	return 0;
}