#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
typedef pair <int, int> pii;
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}

#define N 100005

const int inf = 0x3f3f3f3f;
int n, k, len, a[N], g[2];
set <pii> st[2];
set <pii> :: iterator it[2];
pii rpt[2];
ll s[2], t[2];

int main() {
    scanf("%d %d", &n, &len);
    f1(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &k);
    rpt[0] = pii(inf, 0); rpt[1] = pii(-inf, 0);
    f0(i, 0, 2) it[i] = st[i].insert(rpt[i]).x;
    ll sum = 0, ans = 0;
    f1(i, 1, n) {
        if (i > len) {
            i -= len;
            sum -= a[i];
            if (a[i] > 0) {
                if (a[i] > (it[0] -> x) || it[0] -> y == i) {
                    g[0] --; t[0] -= a[i];
                    if (it[0] -> y == i) it[0] = next(it[0]);
                }
                st[0].erase(pii(a[i], i)), s[0] -= a[i];
            }
            else if (a[i] < 0) {
                if (a[i] <= (it[1] -> x)) {
                    g[1] --; t[1] -= a[i];
                    if (it[1] -> y == i) it[1] = prev(it[1]);
                }
				st[1].erase(pii(a[i], i)), s[1] -= a[i];
            }
            i += len;
        }
        sum += a[i];
        if (a[i] > 0) {
            st[0].insert(pii(a[i], i));
            s[0] += a[i];
            if (a[i] >= (it[0] -> x)) g[0] ++, t[0] += a[i];
        }
        else if (a[i] < 0) {
            st[1].insert(pii(a[i], i));
            s[1] += a[i];
            if (a[i] < (it[1] -> x)) g[1] ++, t[1] += a[i];
        }
        if (i < len) continue;
        f0(ii, 0, 2) {
            if (st[ii].size() <= k + 1) chkmax(ans, abs(sum - 2 * s[ii]));
            else {
                while (g[ii] < k) {
                    g[ii] ++;
                    if (!ii) it[0] = prev(it[0]);
                    else it[1] = next(it[1]);
                    t[ii] += it[ii] -> x;
                }
                while (g[ii] > k) {
                    g[ii] --;
                    t[ii] -= it[ii] -> x;
                    if (!ii) it[0] = next(it[0]);
                    else it[1] = prev(it[1]);
                }
                chkmax(ans, abs(sum - 2 * t[ii]));
            }
        }
    }
    printf("%I64d\n", ans);
	return 0;
}