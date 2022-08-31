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
const ll inf = 2e18;
ll pw[maxn];
int main() {
    pw[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pw[i] = pw[i - 1] * 2;
        if (pw[i] > inf) pw[i] = inf;
    }
    int t;
    cin >> t;
    while (t--) {
        int n; ll k;
        vi cur;
        cin >> n >> k;
        if (k > pw[n - 1]) cout << "-1" << endl;
        else {
            while (k) {
                for (int j = 1; j <= n; j++) {
                    if (k == pw[max(n - j - 1, 0)]) {
                        cur.pb(j);
                        cur.pb(n - j);
                        k = 0;
                        break;
                    } 
                    else {
                        if (k > pw[n - j - 1]) k -= pw[n - j - 1];
                        else {
                            cur.pb(j);
                            n -= j;
                            break;
                        }
                    }
                }
            }
            int ls = 0;
            for (auto v : cur) {
                for (int h = v; h >= 1; h--)
                    printf("%d ", ls + h);
                ls += v;
            }
            printf("\n");
        }

    }
    return 0;
}