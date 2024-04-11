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
int c[200010];
int d[200010];
int lo = INT_MIN, hi = INT_MAX;

int main() {
	scanf("%d", &n);

	int cur = 0;

	rep(i, n) {
		scanf("%d%d", &c[i], &d[i]);

		if (d[i] == 1) {
			lo = max(lo, 1900 - cur);
		} else {
			hi = min(hi, 1899 - cur);
		}

		cur += c[i];
	}

	if (hi == INT_MAX) {
		puts("Infinity");
	} else if (lo > hi) {
		puts("Impossible");
	} else {
		printf("%d\n", hi + cur);
	}

	return 0;
}