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

#define N 1000010
bool a[N+5];
int phi[N+5];
int p[N], L;
int c[N], CL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	a[1] = 1;
	phi[1] = 1;
	for (int i = 2; i <= N; i ++) {
		if (!a[i]) {
			p[L++] = i;
			phi[i] = i-1;
		}
		for (int j = 0; j < L && i*p[j] <= N; j ++) {
			a[i*p[j]] = 1;
			if (i%p[j] != 0) {
				phi[i*p[j]] = phi[i]*(p[j]-1);
			} else {
				phi[i*p[j]] = phi[i]*p[j];
				break;
			}
		}
	}

	int n, k;
	cin >> n >> k;
	set<PII> A;
	for (int i = 3; i <= n; i ++) c[CL++] = phi[i];
	sort(c, c+CL);
	ll S = 1;
	for (int i = 0; i < k; i ++) S += c[i];
	if (k >= 2) S++;
	cout << S << endl;
	return 0;
}