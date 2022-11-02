#include <bits/stdc++.h>
using namespace std;
#define N 110
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}

int n, m;
char s[10];
int a[N], b[N], c[N], d[N];

int main() {
    scanf("%d%d", &n, &m);
    int tb = 0, tc = 0;
    for (int i = 0; i < n; i ++) {
        scanf("%s %d", s, &d[i]);
        if (s[0] == 'D') d[i] ++;
        if (s[0] == 'A') b[tb++] = d[i];
        else c[tc++] = d[i];
    }
    for (int i = 0; i < m; i ++) scanf("%d", a + i);
    sort(a, a + m);
    sort(b, b + tb);
    sort(c, c + tc);
    sort(d, d + n);
    int ans = 0;
    if (m >= n) {

        int l = m - 1, r = n - 1;
        while (a[l] >= d[r] && r >= 0) l --, r --;
        if (r < 0) {
            for (int i = 0; i < m; i ++) ans += a[i];
            for (int i = 0; i < tb; i ++) ans -= b[i];
            for (int i = 0, j = 0; i < tc; i ++) {
                while (a[j] < c[i]) j ++;
                ans -= a[j];
                j ++;
            }
        }
    }
    int tmp = 0;
    int l = m - 1, r = 0;
    while (l >= 0 && r < tb && a[l] >= b[r]) tmp += (a[l] - b[r]), l --, r ++;
    chkmax(ans, tmp);
    cout<<ans<<endl;
}