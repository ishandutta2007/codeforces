#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int jt = 1000000007;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

const int maxn = 100005;
char s[1005], x[55], y[55];
int d, d2, m;
int nxt[maxn][10], fail[maxn], nds = 1;
int dp[55][maxn][2][2][2];
bool ok[maxn];

int main() {
    scanf("%s", s + 1);
    scanf("%s", x + 1);
    scanf("%s", y + 1);
    m = strlen(s + 1);
    d = strlen(x + 1); d2 = d / 2;
	cont(i, m - d2 + 1) {
		int now = 1;
		loop(j, d2) {
			if (!nxt[now][s[i + j] - '0']) {
				nxt[now][s[i + j] - '0'] = ++nds;
			}
			now = nxt[now][s[i + j] - '0'];
		}
		ok[now] = 1;
	}
	queue<int> q;
	loop(i, 10) {
		if (nxt[1][i]) {
			q.push(nxt[1][i]);
			fail[nxt[1][i]] = 1;
		}
		else nxt[1][i] = 1;
	}
	while (SZ(q)) {
		int now = q.front(); q.pop();
		loop(i, 10) {
			if (nxt[now][i]) {
				fail[nxt[now][i]] = nxt[fail[now]][i];
				q.push(nxt[now][i]);
			} else {
				nxt[now][i] = nxt[fail[now]][i];
			}
		}
	}
	dp[0][1][1][1][0] = 1;
	loop(i, d) cont(j, nds) loop(el, 2) loop(er, 2) loop(fi, 2) if (dp[i][j][el][er][fi]) {
		int Cl = (el ? x[i + 1] - '0' : 0), Cr = (er ? y[i + 1] - '0' : 9);
		circ(d, Cl, Cr) {
			int nj = nxt[j][d], nel = el && d == Cl, ner = er && d == Cr, nfi = fi || ok[nj];
			add(dp[i + 1][nj][nel][ner][nfi], dp[i][j][el][er][fi]);
		}
	}
	int ans = 0;
	cont(j, nds) loop(el, 2) loop(er, 2) add(ans, dp[d][j][el][er][1]);
	printf("%d\n", ans);
	return 0;
}