#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ld long double

int n, s;
int deg[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		deg[a]++; deg[b]++;
	}

	int numg = 0;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) numg++;
	}

	ld ans = (s+0.0) / numg;
	cout << fixed << setprecision(15) << 2*ans << endl;

}