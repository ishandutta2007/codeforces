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
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
int s[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        map<int, int> hv;
        sort(s + 1, s + n + 1);
        int fl = 0;
        for (int i = 1; i <= n; i++) {
            if (hv[s[i] - k]) fl = 1;
            hv[s[i]] = 1;
        }
        if (fl) printf("YES\n");
        else printf("NO\n");

    }
    return (0-0); //<3
}