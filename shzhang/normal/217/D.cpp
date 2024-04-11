#include <cstdio>
#include <cstdlib>

using namespace std;

#define MOD 1000000007
#define ll long long
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define ull unsigned __int128

bool used[125];

int ans = 0;

int n, m, t;
int cnt[125];

void dfs(int val, ull rep)
{
    if (val == m / 2 + 1) {
        int curcnt = 1;
        for (int i = 0; i < val; i++) {
            if (used[i]) curcnt = mul(curcnt, cnt[i]);
        }
        ans += curcnt;
        if (ans >= MOD) ans -= MOD;
        return;
    }
    ull cur = rep, tmp = (rep << (ull)val) | (rep >> (ull)(m - val)) | (rep >> (ull)val) | (rep << (ull)(m - val));
    tmp |= ((ull)(1) << (ull)(val));
    tmp |= ((ull)(1) << (ull)(m - val));
    cur |= tmp;
    if (!(cur & (ull)(1))) {
        used[val] = true;
        dfs(val+1, cur);
        used[val] = false;
    }
    dfs(val+1, rep);
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= t; i++) {
        int x; scanf("%d", &x); x %= m;
        if (x > m / 2) x = m - x;
        cnt[x]++;
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}