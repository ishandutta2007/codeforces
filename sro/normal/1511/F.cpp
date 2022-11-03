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

const int jt = 998244353;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

int n, m, t;
char s[9][9];
vector<pair<int, int> > lss;
map<pair<int, int>, int> ids;
int son[44][26], nds;
bool fin[44];
string ss[44];

void dfs(int now) {
	loop(i, 26) if (son[now][i]) {
		ss[son[now][i]] = ss[now] + (char)(i + 'a');
		dfs(son[now][i]);
	}
}

struct Matrix {
	int a[500][500];
	Matrix(int x = 0) {
		loop(i, 500) loop(j, 500) a[i][j] = (i == j ? x : 0);
	}
	Matrix operator * (const Matrix &mat) const {
		static Matrix res;
		loop(i, t) loop(j, t) res.a[i][j] = 0;
		loop(i, t) loop(j, t) loop(k, t) add(res.a[i][k], Mul(a[i][j], mat.a[j][k]));
		return res;
	}
} tr;

Matrix ksmii(Matrix a, int b) {
	Matrix ans(1);
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a; b >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	nds = 1;
	cont(i, n) {
		scanf("%s", s[i]); int len = strlen(s[i]);
		int now = 1;
		loop(j, len) {
			if (!son[now][s[i][j] - 'a']) son[now][s[i][j] - 'a'] = ++nds;
			now = son[now][s[i][j] - 'a'];
		}
		fin[now] = 1;
	}
	dfs(1);
	cont(i, nds) cont(j, nds) {
		if (SZ(ss[j]) > SZ(ss[i])) continue;
		bool can = 1;
		loop(k, SZ(ss[j])) if (ss[j][k] != ss[i][SZ(ss[i]) - SZ(ss[j]) + k]) can = 0;
		if (!can) continue;
		ids[mak(i, j)] = SZ(lss);
		lss.emb(i, j);
	}
	t = SZ(lss);
	loop(i, t) {
		int a, b; tie(a, b) = lss[i];
		loop(c, 26) if (son[a][c] && son[b][c]) {
			++tr.a[i][ids[mak(son[a][c], son[b][c])]];
		}
		loop(j, t) {
			int c, d; tie(c, d) = lss[j];
			if (c == 1 || d == 1) continue;
			if (fin[c]) add(tr.a[i][ids[mak(d, 1)]], tr.a[i][j]);
			if (fin[d]) add(tr.a[i][ids[mak(c, 1)]], tr.a[i][j]);
			if (fin[c] && fin[d]) add(tr.a[i][0], tr.a[i][j]);
		}
	}
	tr = ksmii(tr, m);
	printf("%d\n", tr.a[0][0]);
	return 0;
}