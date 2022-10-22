#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
int col[200010];
bool pr[200010];

int main() {
	memset(col, -1, sizeof(col));
	cin >> n;

	int ma = 0;

	for (int i = 2; i <= n+1; ++i) {
		if (pr[i]) continue;
		col[i] = 1;
		for (int j = i * 2; j <= n+1; j += i) {
			pr[j] = 1;
			col[j] = 2;
		}
	}

	for (int i = 2; i <= n+1; ++i) {
		ma = max(ma, col[i]);
	}

	printf("%d\n", ma);

	for (int i = 2; i <= n+1; ++i) printf("%d%c", col[i], i == n+1 ? '\n' : ' ');

	return 0;
}