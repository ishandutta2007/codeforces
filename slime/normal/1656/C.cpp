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
const int maxn =200005;
int a[maxn];
int t;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int hv = 0;
        int fl = 0;
        int hvd = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) hv = 1;
            if (i < n && a[i + 1] - a[i] == 1) hvd = 1;
        }
        fl = 1;
        if (hv && hvd) { fl = 0;
            
        }
        if (fl) printf("YES\n");
        else printf("NO\n");
    }
    return (0-0); //<3
}