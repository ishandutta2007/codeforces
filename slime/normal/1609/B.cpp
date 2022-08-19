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
int ans[maxn];
int x[maxn];
char inp[maxn];
bool chk(int r) {
    if (x[r] == 1 && x[r + 1] == 2 && x[r + 2] == 3) return 1;
    return 0;
}
int tot = 0;
int main() {
    int n, q;
    cin >> n >> q;
    scanf("%s", inp + 1);
    for (int i = 1; i <= n; i++)
        x[i] = inp[i] - 'a' + 1;
    for (int i = 1; i <= n; i++)
        tot += chk(i);
    while (q--) {
        int p;
        char u[5];
        scanf("%d%s", &p, u);
        int to = u[0] - 'a' + 1;
        for (int m = max(1, p - 2); m <= p; m++)
            tot -= chk(m);
        x[p] = to;
        for (int m = max(1, p - 2); m <= p; m++)
            tot += chk(m);
        printf("%d\n", tot);
    }
    return (0-0); //<3
}