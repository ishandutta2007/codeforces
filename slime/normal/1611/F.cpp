#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 200005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n, s;
ll a[maxn];
int st[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) 
            cin >> a[i], a[i] += a[i - 1];
        // first < a[i] - s
        int top = 0;
        int ans = 0;
        pi res;
        for (int i = n; i >= 1; i--) {
            while (top && a[st[top - 1]] >= a[i]) top--;
            st[top++] = i;
            int mpl = n + 1;
            int l = 0, r = top - 1;
            ll fd = a[i - 1] - s;
            // for (int j = 0; j < top; j++)
            //     cout << st[j] << ' ';
            // cout << endl;
            if (a[st[0]] < fd) {
                while (l < r) {
                    int p = (l + r) >> 1;
                    //cout << p << ' ' << a[p + 1] << endl;
                    if (a[st[p + 1]] < fd) l = p + 1;
                    else r = p;
                }
                mpl = st[l];
            }
           // cout << "!!!" << i << ' ' << mpl << endl;
            if (chkmax(ans, mpl - i)) res = mp(i, mpl - 1);
        }
        if (ans == 0) cout << -1 << endl;
        else cout << res.fi << ' ' << res.se << endl;
    }
    return 0;
}