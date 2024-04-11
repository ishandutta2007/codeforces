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

int n, q;

char s0[105], t[100005];
char w[1000005];
char s[3000005];
char s1[4000005];
char s2[4000005];
int kmp[1000005];
int z1[4000005], z2[4000005];

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

void Z(char* a, int* z, int len)
{
    // From CPH
    int x = 0, y = 0;
    for (int i = 1; i < len; i++) {
        z[i] = max(0, min(z[i-x], y - i + 1));
        while (i + z[i] < len && a[z[i]] == a[i + z[i]]) {
            x = i; y = i + z[i]; z[i]++;
        }
    }
}

int psum[100005][26];

int pwr2[100005];
int ipwr2[100005];

int main()
{
    pwr2[0] = ipwr2[0] = 1;
    for (int i = 1; i <= 100004; i++) {
        pwr2[i] = mul(pwr2[i-1], 2);
        ipwr2[i] = mul(ipwr2[i-1], 500000004);
    }
    scanf("%d%d", &n, &q);
    scanf("%s", s0);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            psum[i][j] = psum[i-1][j];
        }
        psum[i][t[i] - 'a'] += pwr2[n - i];
        if (psum[i][t[i] - 'a'] >= MOD) psum[i][t[i] - 'a'] -= MOD;
        //printf("! %d\n", psum[i][1]);
    }
    int s0len = strlen(s0);
    for (int qry = 1; qry <= q; qry++) {
        int k; scanf("%d", &k); scanf("%s", w);
        int len = strlen(w);
        for (int i = 0; i < s0len; i++) s[i] = s0[i];
        int slen = s0len;
        int curlvl = 0;
        while (slen < len && curlvl < k) {
            s[slen] = t[curlvl + 1];
            for (int i = slen + 1; i < slen * 2 + 1; i++) {
                s[i] = s[i - slen - 1];
            }
            slen = slen * 2 + 1;
            curlvl++;
        }
        s[slen] = '\0';
        kmp[0] = 0;
        for (int i = 1; i < len; i++) {
            int cur = kmp[i-1];
            while (w[cur] != w[i]) {
                if (cur == 0) {
                    cur = -1; break;
                }
                cur = kmp[cur - 1];
            }
            kmp[i] = cur + 1;
        }
        int occur = 0; int nxt = 0;
        for (int i = 0; i < slen; i++) {
            while (w[nxt] != s[i]) {
                if (nxt == 0) {
                    nxt = -1; break;
                }
                nxt = kmp[nxt - 1];
            }
            nxt++;
            if (nxt == len) {
                occur++;
                //printf("%d ", i);
            }
        }
        for (int i = 0; i < slen; i++) {
            s1[slen - i - 1] = s[i];
            s2[i] = s[i];
        }
        s1[slen] = s2[slen] = '#';
        for (int i = 0; i < len; i++) {
            s1[slen + (len - i)] = w[i];
            s2[slen + i + 1] = w[i];
        }
        s1[slen + len + 1] = s2[slen + len + 1] = '\0';
        Z(s1, z1, slen + len + 1);
        Z(s2, z2, slen + len + 1);

        int match_cnt[26];
        for (int i = 0; i < 26; i++) match_cnt[i] = 0;
        for (int i = 0; i < len; i++) {
            if (z1[slen + len + 1 - i] >= i && z2[slen + i + 2] >= len - i - 1) {
                match_cnt[w[i] - 'a']++;
            }
        }

        int ans = mul(pwr2[k - curlvl], occur);
        for (int i = 0; i < 26; i++) {
            //printf("%d %d %d\n", match_cnt[i], (psum[k][i] - psum[curlvl][i] + MOD) % MOD, ipwr2[n - k]);
            ans += mul(match_cnt[i], mul((psum[k][i] - psum[curlvl][i] + MOD) % MOD, ipwr2[n - k]));
            if (ans >= MOD) ans -= MOD;
        }

        printf("%d\n", ans);

        /*printf("%s\n", s);
        for (int i = 0; i < 26; i++) {
            if (match_cnt[i]) {
                printf("%c %d ", 'a' + i, match_cnt[i]);
            }
        }
        printf("\n");*/
        /*printf("%s\n", s1);
        for (int i = 0; i < slen + len + 1; i++) {
            printf("%d ", z1[i]);
        }
        printf("\n");*/
    }
    return 0;
}