//hey alc
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
const int maxn = 200005;
int cnt[maxn];
int hv[maxn];
int a[maxn];
int b[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int fl = 1;
        if (n % 2) fl = 0;
        else {
            int cnt = 1;
            for (int i = 1; i <= n; i += 2)
                b[i] = a[cnt++];
            for (int i = 2; i <= n; i += 2)
                b[i] = a[cnt++];
            for (int i = 1; i <= n; i++) {
                int nx = b[i + 1];
                if (i == n) nx = b[1];
                if (b[i] == nx) fl = 0;
            }
        }
        if (fl) {
            printf("Yes\n");
            for (int i = 1; i <= n; i++)
                printf("%d ", b[i]);
            printf("\n");
        }
        else printf("No\n");
    }
    return (0-0); //<3
}