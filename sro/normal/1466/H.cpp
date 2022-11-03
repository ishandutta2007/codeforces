/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int jt = 1000000007;
int n;
int p[44];
bool lgl[44];
vector<int> cns;
int pre[44];
int ptr, len[44], siz[44];
int jc[44], C[44][44];
int dp[2222], mii[44][44];
int msk, all;
int cs[45];

void dfs(int cur, int nmsk, int siz, int rc) {
	if(cur == ptr + 1) {
		if(msk != nmsk) dp[msk] = (dp[msk] + 1ll * rc * dp[nmsk] % jt * mii[siz][all - siz]) % jt;
		return;
	}
	loop(i, cs[cur] + 1) {
		int mmsk = nmsk + pre[cur - 1] * (cs[cur] - i);
		int nsiz = siz + ::siz[cur] * (cs[cur] - i);
		int nrc = 1ll * rc * ((i & 1) ? jt - C[cs[cur]][i] : C[cs[cur]][i]) % jt;
		dfs(cur + 1, mmsk, nsiz, nrc);
	}
}

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", p + i);
	cont(i, n) if(!lgl[i]) {
		int j = i, cnt = 0;
		while(!lgl[j]) {
			lgl[j] = 1;
			++cnt;
			j = p[j];
		}
		cns.pub(cnt);
	}
	sort(all(cns)); pre[0] = 1;
	int j = 0;
	vector<int> szs;
	loop(i, SZ(cns)) {
		while(j < SZ(cns) && cns[i] == cns[j]) ++j;
		len[++ptr] = j - i;
		siz[ptr] = cns[i];
		pre[ptr] = pre[ptr - 1] * (len[ptr] + 1);
		i = j - 1;
	}
	jc[0] = 1; cont(i, n) jc[i] = 1ll * jc[i - 1] * i % jt;
	loop(i, n + 1) C[i][0] = 1;
	cont(i, n) cont(j, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % jt;
	loop(i, n) {
		mii[i][0] = 1;
		loop(j, i + 1) mii[i][1] = (mii[i][1] + 1ll * jc[j] * jc[n - j - 1] % jt * C[i][j]) % jt;
		circ(j, 2, n) mii[i][j] = 1ll * mii[i][j - 1] * mii[i][1] % jt;
	}
	dp[0] = 1;
	cont(i, pre[ptr] - 1) {
		msk = i; all = 0;
		cont(j, ptr) cs[j] = i % pre[j] / pre[j - 1], all += cs[j] * siz[j];
		dfs(1, 0, 0, jt - 1);
	}
	printf("%d\n", dp[pre[ptr] - 1]);
	return 0;
}