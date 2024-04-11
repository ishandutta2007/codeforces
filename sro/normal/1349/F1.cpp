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

int inline ksmii(int a, int b) {
	if (!b) return 1;
	int x = ksmii(a, b >> 1);
	x = 1ll * x * x % jt;
	if (b & 1) x = 1ll * x * a % jt;
	return x;
}

int n;
int jc[100005], fjc[100005];
int ora[5005][5005];

int main() {
	scanf("%d", &n);
	jc[0] = 1; cont(i, n) jc[i] = 1ll * i * jc[i - 1] % jt;
	fjc[n] = ksmii(jc[n], jt - 2);
	range(i, n, 1, -1) fjc[i - 1] = 1ll * i * fjc[i] % jt;
	cont(i, n + 1) ora[i][0] = 1;
	cont(i, n) cont(j, i) ora[i][j] = (1ll * (i - j) * ora[i - 1][j - 1] + 1ll * (j + 1) * ora[i - 1][j]) % jt;
	loop(i, n) {
		int ans = 0;
		circ(j, max(i, 1), n) ans = (ans + 1ll * jc[n] * fjc[j] % jt * ora[j][i]) % jt;
		printf("%d ", ans);
	}
	return 0;
}