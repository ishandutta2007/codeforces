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

#define N 1010
ll a[N], b[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i ++)
		a[i*i%m] += n/m;
	for (int i = 0; i < n%m; i ++)
		a[(i+1)*(i+1)%m] ++;
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < m; j ++)
			b[(i+j)%m] += a[i]*a[j];
	cout << b[0] << endl;
	return 0;
}