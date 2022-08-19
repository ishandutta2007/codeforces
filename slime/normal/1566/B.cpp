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
const int maxn = 100005;
char inp[maxn];
int n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", inp + 1);
        int l = strlen(inp + 1);
        int hv[3] = {0, 0, 0};
        int f = l + 1, ed = 0;
        for (int i = 1; i <= l; i++) {
            hv[inp[i] - '0'] += 1;
            if (inp[i] == '0') chkmin(f, i), chkmax(ed, i);
        }
        int ans = 0;
        while (hv[ans]) ans += 1;
        chkmin(ans, hv[0]);
        if (ans == 2 && hv[0] == ed - f + 1) ans = 1;
        printf("%d\n", ans);
    }
    return (0-0); //<3
}