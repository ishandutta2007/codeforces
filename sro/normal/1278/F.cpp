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
int S[5005][5005];
int n, m, k;

int inline ksmii(int a, int b) {
	if (!b) return 1;
	int x = ksmii(a, b >> 1);
	x = 1ll * x * x % jt;
	if (b & 1) x = 1ll * x * a % jt;
	return x;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	S[0][0] = 1;
	cont(i, k) cont(j, k) S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % jt;
	int ans = 0, x = 1;
	loop(i, k + 1) ans = (ans + 1ll * S[k][i] * x % jt * ksmii(m, jt - i - 1)) % jt, x = 1ll * x * (n - i) % jt;
	printf("%d\n", ans);
	return 0;
}