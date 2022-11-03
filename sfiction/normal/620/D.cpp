#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E3 + 10;

int n, m;
int a[MAXN], b[MAXN];
pair<ll, pair<int, int> > c[MAXN * MAXN], d[MAXN * MAXN];
ll sa, sb;

ll ans;
vector<int> ansf, ansg;

void update(vector<int> &f, vector<int> &g){
	ll ta = sa, tb = sb;
	for (int i = 0; i < f.size(); ++i){
		ta += b[g[i]] - a[f[i]];
		tb += a[f[i]] - b[g[i]];
	}
	if (ans > llabs(ta - tb)){
		ans = llabs(ta - tb);
		ansf = f;
		ansg = g;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), sa += a[i];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]), sb += b[i];
	ans = llabs(sa - sb);

	vector<int> f(1), g(1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			f[0] = i, g[0] = j;
			update(f, g);
		}

	if (n > 1 && m > 1){
		ll det = sb - sa;
		int N = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j){
				c[N].st = ((ll)a[i] + a[j] << 1) + det;
				c[N++].nd = PII(i, j);
			}
		int M = 0;
		for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < m; ++j){
				d[M].st = (ll)b[i] + b[j] << 1;
				d[M++].nd = PII(i, j);
			}
		sort(c, c + N);
		sort(d, d + M);
		int r = 0;
		f = g = vector<int>(2);
		for (int i = 0; i < N; ++i){
			for (; r < M && d[r].st <= c[i].st; ++r);
			f[0] = c[i].nd.st, f[1] = c[i].nd.nd;
			if (0 < r){
				g[0] = d[r - 1].nd.st, g[1] = d[r - 1].nd.nd;
				update(f, g);
			}
			if (r < M){
				g[0] = d[r].nd.st, g[1] = d[r].nd.nd;
				update(f, g);
			}
		}
	}
	printf("%I64d\n", ans);
	printf("%d\n", ansf.size());
	for (int i = 0; i < ansf.size(); ++i)
		printf("%d %d\n", ansf[i] + 1, ansg[i] + 1);
	return 0;
}