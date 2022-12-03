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

int TC;
int n;
int a[110];
bool f[1000010];
bool ng[1000010];
int b[110];

void solve()
{
	memset(f, 0, sizeof(f));
	memset(ng, 0, sizeof(ng));

	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);

	vi ban;

	rep(i, n) {
		rep(j, i) {
			ban.pb(a[i] - a[j]);
			f[a[i] - a[j]] = 1;
		}
	}

	b[0] = 1;

	for (int i = 1; i < n; ++i) {
		for (int x : ban) {
			if (b[i-1] + x <= 1000000) ng[b[i-1] + x] = 1;
		}

		int x = b[i-1] + 1;
		while (ng[x] && x <= 1000000) ++x;
		b[i] = x;
	}

	assert(b[n-1] <= 1000000);
	puts("YES");
	rep(i, n) printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
}

int main() {
	scanf("%d", &TC);
	while (TC--) solve();
	return 0;
}