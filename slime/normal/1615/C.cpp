//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
char s[maxn], t[maxn];
int n;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        int mn = 1e9;
        for (int j = 0; j < 2; j++) {
            int fl = 0;
            int hv = 0;
            int toth = 0;
            int cnt[2][2] = {{0, 0}, {0, 0}};
            for (int i = 1; i <= n; i++) {
                int u = s[i] - '0';
                int v = t[i] - '0';
                cnt[u][u ^ j ^ v] += 1;
                if ((u ^ j) != v) 
                    fl += 1;
                if (u) toth = 1;
            }
            if ((fl & 1) != j) continue;
            if (fl && (!toth)) continue;
            int tot = 0;
            while (cnt[0][1] || cnt[1][1]) {
                tot += 1;
                if (tot > 10 * n) {
                    tot = 1e9;
                    break;
                }
                if (cnt[1][1]) {
                    cnt[1][1] -= 1;
                    swap(cnt[0][1], cnt[1][1]);
                    swap(cnt[0][0], cnt[1][0]);
                    cnt[1][0] += 1;
                }
                else {
                    cnt[1][0] -= 1;
                    swap(cnt[0][1], cnt[1][1]);
                    swap(cnt[0][0], cnt[1][0]);
                    cnt[1][1] += 1;
                }
            }
            chkmin(mn, tot);
        }
        if (mn > 1e8) mn = -1;
        printf("%d\n", mn);
    }
    return (0-0); //<3
}