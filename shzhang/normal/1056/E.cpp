#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int n;
char bin[100005];
char s[1000005];
int sa[1000005];
int rk[1000005];
int tmp[1000005];
int tmp2[1000005];
int x[1000005];
int y[1000005];
int h[1000005];
int height[1000005];
int rmq[1000005][24];

int Rmq(int rmqa[1000005][24], int l, int r)
{
    if (l > r) swap(l, r);
    l++;
    //printf("%d %d ", l, r);
    int ans = 10000000;
    for (int i = 19; i >= 0; i--) {
        if (l + (1 << i) - 1 <= r) {
            ans = min(ans, rmqa[l][i]); l += (1 << i);
        }
    }
    //printf("%d\n", ans);
    return ans;
}

void build_sa(void)
{
    for (int i = 0; i < n; i++) tmp[(int)s[i]]++;
    for (int i = 1; i < 300; i++) tmp[i] += tmp[i-1];
    for (int i = n - 1; i >= 0; i--) rk[i] = tmp[(int)s[i]] - 1;
    for (int a = 1; a < n; a <<= 1) {
        for (int i = 0; i < n; i++) x[i] = rk[i];
        for (int i = 0; i < n; i++) y[i] = rk[i + a];
        for (int i = 0; i <= n; i++) tmp[i] = 0;
        for (int i = 0; i < n; i++) tmp[y[i]]++;
        for (int i = 1; i <= n; i++) tmp[i] += tmp[i-1];
        for (int i = n - 1; i >= 0; i--) tmp2[--tmp[y[i]]] = i;
        for (int i = 0; i <= n; i++) tmp[i] = 0;
        for (int i = 0; i < n; i++) tmp[x[i]]++;
        for (int i = 1; i <= n; i++) tmp[i] += tmp[i-1];
        for (int i = n - 1; i >= 0; i--) sa[--tmp[x[tmp2[i]]]] = tmp2[i];
        for (int i = 0; i < n; i++) rk[sa[i]] =
            (i && x[sa[i-1]] == x[sa[i]] && y[sa[i-1]] == y[sa[i]] ? rk[sa[i-1]] : i);
        for (int i = 0; i < n; i++) rk[i]++;
    }
    for (int i = 0; i < n; i++) rk[sa[i]] = i;
}

int main()
{
    scanf("%s", bin);
    int cnt0 = 0; int cnt1=  0;
    for (int i = 0; bin[i]; i++) {
        if (bin[i] == '1') cnt1++;
        else cnt0++;
    }
    scanf("%s", s);
    n = strlen(s);
    build_sa();
    /* height[i]: lcp(sa[i], sa[i-1])
       h[i]: lcp(i, sa[rk[i]-1]) */
    if (rk[0])
        while (s[h[0]] == s[sa[rk[0]-1] + h[0]]) h[0]++;
    for (int i = 1; i < n; i++) {
        if (!rk[i]) continue;
        h[i] = max(h[i-1]-1, 0);
        while (s[i + h[i]] == s[sa[rk[i]-1] + h[i]]) h[i]++;
    }
    for (int i = 0; i < n; i++) height[rk[i]] = h[i];
    for (int i = 0; i < n; i++) rmq[i][0] = height[i];
    for (int pwr = 1; pwr <= 19; pwr++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << (pwr - 1)) >= n) {
                rmq[i][pwr] = rmq[i][pwr-1];
            } else {
                rmq[i][pwr] = min(rmq[i][pwr-1], rmq[i + (1 << (pwr - 1))][pwr-1]);
            }
        }
    }
    //for (int i = 0; i < n; i++) printf("%d ", sa[i]);
    //printf("\n");
    //for (int i = 0; i < n; i++) printf("%d ", height[i]);
    //printf("\n");
    int ans = 0;
    for (int siz0 = 1; siz0 * cnt0 <= n; siz0++) {
        if ((n - siz0 * cnt0) % cnt1) continue;
        int siz1 = (n - siz0 * cnt0) / cnt1;
        if (!siz1) continue;
        //printf("%d %d\n", siz0, siz1);
        int zero_off = -1, one_off = -1;
        int curloc = 0;
        bool failed = false;
        for (int i = 0; bin[i]; i++) {
            if (bin[i] == '0') {
                if (zero_off == -1) {
                    zero_off = curloc; curloc += siz0; continue;
                } else {
                    //printf("0: curloc %d, zerooff %d\n", curloc, zero_off);
                    if (Rmq(rmq, rk[curloc], rk[zero_off]) < siz0) failed = true;
                }
                curloc += siz0;
            } else {
                if (one_off == -1) {
                    one_off = curloc; curloc += siz1; continue;
                } else {
                    if (Rmq(rmq, rk[curloc], rk[one_off]) < siz1) failed = true;
                }
                curloc += siz1;
            }
        }
        if (siz0 == siz1 && Rmq(rmq, rk[zero_off], rk[one_off]) >= siz0) failed = true;
        if (!failed) /*printf("%d %d\n", siz0, siz1),*/ ans++;
    }
    printf("%d", ans);
    return 0;
}