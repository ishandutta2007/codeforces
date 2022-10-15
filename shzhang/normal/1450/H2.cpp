#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 998244353
#define mul(a, b) (F.reduce((ll)(a) * (ll)(b)))

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod F(998244353);

int n, m;
char s[200005];
int fact[200005];
int ifact[200005];

int C(int x, int y)
{
    return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

void cntpos(vector<int>& pos, int& start, int& oddsp, int& evensp)
{
    start = 0, oddsp = 0, evensp = 0;
    for (int i = 0; i < pos.size(); i++) {
        char chr = s[pos[i]]; bool isodd = (pos[i] % 2 != 0);
        if (chr == '?') {
            if (isodd) oddsp++;
            else evensp++;
        } else if (chr == 'b') {
            if (isodd) start++;
            else start--;
        } else {
            if (isodd) start--;
            else start++;
        }
    }
}

int cntdist_base(int N, int start, int oddsp, int evensp, int* ans)
{
    for (int x = 0; x <= 2 * N; x++) ans[x] = 0;
    for (int x = 0; x <= oddsp + evensp; x++) {
        int val = start - oddsp - evensp + 2 * x;
        int valpos = val + N;
        ans[valpos] = C(oddsp + evensp, x);
    }
    return (start - oddsp - evensp + n + 1000000) % 2;
}

int cntdist(vector<int>& pos, int* ans)
{
    int start, oddsp, evensp;
    cntpos(pos, start, oddsp, evensp);
    cntdist_base(pos.size(), start, oddsp, evensp, ans);
    return cntdist_base(pos.size(), start, oddsp, evensp, ans);
}

int pdist[400005];
int psum[400005][4];
int psum2[400005][4];
int inv2[200005];

int question_marks = 0;

bool exclude[200005];

#define BLKSIZE 500
int pdist2[BLKSIZE * 2 + 5];

void solve_queries()
{
    for (int S = 1; S <= m; S += BLKSIZE) {
        vector<pair<int, char> > ops;
        for (int i = S; i < S + BLKSIZE && i <= m; i++) {
            int pos; char chr[5];
            scanf("%d%s", &pos, chr);
            ops.push_back(make_pair(pos, chr[0]));
        }
        for (int i = 0; i < ops.size(); i++) {
            exclude[ops[i].first] = true;
        }
        exclude[1] = true;
        vector<int> remain;
        vector<int> changed;
        for (int i = 1; i <= n; i++) {
            if (!exclude[i]) remain.push_back(i);
            else changed.push_back(i);
        }
        int parity = cntdist(remain, pdist);
        for (int i = 0; i <= 2 * remain.size(); i++) {
            //printf("%d ", pdist[i]);
            if (i) {
                for (int j = parity; j < 4; j += 2) psum[i][j] = psum[i-1][j];
                for (int j = parity; j < 4; j += 2) psum2[i][j] = psum2[i-1][j];
            } else {
                psum[0][0] = psum[0][1] = psum[0][2] = psum[0][3] = 0;
                psum2[0][0] = psum2[0][1] = psum2[0][2] = psum2[0][3] = 0;
            }
            if (!pdist[i]) continue;
            int mod4v = (10000000 + i - remain.size()) % 4;
            psum[i][mod4v] += mul(i - remain.size() + MOD, pdist[i]);
            if (psum[i][mod4v] >= MOD) psum[i][mod4v] -= MOD;
            psum2[i][mod4v] += pdist[i];
            if (psum2[i][mod4v] >= MOD) psum2[i][mod4v] -= MOD;
        }
        //printf("\n");
        for (int i = 2 * remain.size() + 1; i <= 2 * BLKSIZE + 10; i++) {
            for (int j = parity; j < 4; j += 2) psum[i][j] = psum[i-1][j];
            for (int j = parity; j < 4; j += 2) psum2[i][j] = psum2[i-1][j];
        }

        int start, oddsp, evensp;
        cntpos(changed, start, oddsp, evensp);

        for (int i = 0; i < ops.size(); i++) {
            exclude[ops[i].first] = false;
            if (s[ops[i].first] == '?') question_marks--;
            if (s[ops[i].first] == '?') {
                if (ops[i].first % 2) oddsp--;
                else evensp--;
            } else if (s[ops[i].first] == 'b') {
                if (ops[i].first % 2) start--;
                else start++;
            } else {
                if (ops[i].first % 2) start++;
                else start--;
            }
            s[ops[i].first] = ops[i].second;
            if (s[ops[i].first] == '?') question_marks++;
            if (s[ops[i].first] == '?') {
                if (ops[i].first % 2) oddsp++;
                else evensp++;
            } else if (s[ops[i].first] == 'b') {
                if (ops[i].first % 2) start++;
                else start--;
            } else {
                if (ops[i].first % 2) start--;
                else start++;
            }
            cntdist_base(changed.size(), start, oddsp, evensp, pdist2);
            int ans = 0;
            /*for (int j = 0; j <= 2 * changed.size(); j++) {
                printf("%d ", pdist2[j]);
            }
            printf("\n");*/
            for (int j = 0; j <= 2 * changed.size(); j++) {
                if (!pdist2[j]) continue;
                int val = j - changed.size();
                int needed_mod4 = (10000000-val) % 4;
                if (needed_mod4 % 2 != parity) continue;
                // final val >= 0
                //printf("%d %d\n", psum[2 * remain.size()][needed_mod4], psum[remain.size() - val][needed_mod4]);
                int e_add = psum[2 * remain.size()][needed_mod4] - ((int)remain.size() >= val ? psum[remain.size() - val][needed_mod4] : 0);
                if (e_add < 0) e_add += MOD;
                int cnt_add = psum2[2 * remain.size()][needed_mod4] - ((int)remain.size() >= val ? psum2[remain.size() - val][needed_mod4] : 0);
                if (cnt_add < 0) cnt_add += MOD;
                int add_val = e_add + mul(val + MOD, cnt_add);
                if (add_val >= MOD) add_val -= MOD;
                //printf("val=%d %d %d %d\n", val, e_add, cnt_add, add_val);
                // final val < 0
                e_add = (remain.size() - val - 1 >= 0 ? psum[remain.size() - val - 1][needed_mod4] : 0);
                cnt_add = (remain.size() - val - 1 >= 0 ? psum2[remain.size() - val - 1][needed_mod4] : 0);
                int add_val2 = mul(MOD-val, cnt_add) - e_add;
                if (add_val2 < 0) add_val2 += MOD;
                //printf("%d %d %d\n", e_add, cnt_add, add_val2);
                ans += mul(add_val + add_val2, pdist2[j]);
                if (ans >= MOD) ans -= MOD;
            }
            //printf("\n");
            ans = mul(ans, inv2[question_marks + 1]);
            printf("%d\n", ans);
        }
    }
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) fact[i] = mul(i, fact[i-1]);
    ifact[200000] = fpow(fact[200000], MOD - 2);
    for (int i = 199999; i >= 0; i--) ifact[i] = mul(ifact[i+1], i+1);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') question_marks++;
    }
    vector<int> pos; for (int i = 1; i <= n; i++) pos.push_back(i);
    cntdist(pos, pdist);
    int ans = 0;
    for (int i = 0; i <= 2 * n; i++) {
        int absv = (i - n > 0 ? i - n : n - i);
        if ((absv + 1000000) % 4) continue;
        ans += mul(absv, pdist[i]);
        if (ans >= MOD) ans -= MOD;
    }
    inv2[0] = 1;
    int inv2val = fpow(2, MOD - 2);
    for (int i = 1; i <= n + 1; i++) inv2[i] = mul(inv2[i-1], inv2val);
    ans = mul(ans, inv2[question_marks + 1]);
    printf("%d\n", ans);
    solve_queries();
    return 0;
}