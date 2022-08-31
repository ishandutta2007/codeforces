//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
int f[maxn];
char s[maxn];
int hv[maxn];
int main() {
    f[0] = f[1] = 0;
    const int S = 505;
    for (int i = 2; i <= S; i++) {
        for (int j = 0; j < S; j++)
            hv[j] = 0;
        for (int j = 0; j <= i - 2; j++) {
            hv[f[j] ^ f[i - 2 - j]] = 1;
        }
        f[i] = 0;
        while (hv[f[i]]) f[i] += 1;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; i++)
            if (s[i] == 'R') cnt[0] += 1;
            else cnt[1] += 1;
        vi cur;
        for (int i = 1; i <= n; ) {
            int j = i;
            while (j + 1 <= n && s[j + 1] != s[j]) j += 1;
            cur.pb(j - i + 1);
            i = j + 1;
        }
        int tot = 0;
        for (auto v : cur) {
            int g = v;
            if (g > S) {
                int e = (g - S) / 34 * 34 + 34;
                g -= e;
            }
            tot ^= f[g];
        }
        if (tot) cnt[0] += 1;
        if (cnt[0] > cnt[1]) printf("Alice\n");
        else printf("Bob\n");
    }

    return (0-0); //<3
}
/*
1

4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19*/