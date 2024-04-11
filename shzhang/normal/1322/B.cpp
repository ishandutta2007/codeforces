#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
int a[400005];

int bt;

bool cmp(int A, int b)
{
    return A % (1 << bt) < b % (1 << bt);
}

int tst(int bit)
{
    bt = bit;
    /* highbit, carry */
    int cnt[2][2]; cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
    for (int i = 1; i <= n; i++) {
        (a[i] & (1 << bit) ? cnt[1][0] : cnt[0][0])++;
    }
    sort(a + 1, a + n + 1, cmp);
    ll ans = 0;
    int r = n + 1;
    for (int l = 1; l <= n; l++) {
        while (r > 1 && a[l] % (1 << bit) + a[r - 1] % (1 << bit) >= (1 << bit)) {
            r--;
            if (a[r] & (1 << bit)) {
                cnt[1][0]--; cnt[1][1]++;
            } else {
                cnt[0][0]--; cnt[0][1]++;
            }
        }
        int own_highbit = (a[l] & (1 << bit) ? 1 : 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (own_highbit ^ i ^ j) {
                    ans += cnt[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((a[i] * 2) & (1 << bit)) ans--;
    }
    ans /= 2LL;
    if (ans % 2LL) return 1 << bit;
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 0;
    for (int i = 0; i < 27; i++) {
        ans |= tst(i);
    }
    //for (int i = 1; i <= n; i++) ans ^= (a[i] * 2);
    printf("%d", ans);
    return 0;
}