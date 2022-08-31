//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<ll, ll>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 300005;
int a[maxn];
int nx[maxn];
int nxsm[maxn];
int st[maxn], top;
int n;
void work() {
    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[st[top - 1]] > a[i]) top--;
        nxsm[i] = n + 1;
        if (top) nxsm[i] = st[top - 1];
        st[top++] = i;
    }
    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[st[top - 1]] < a[i])
            top--;
        st[top++] = i;
        if (nxsm[i] == i + 1) continue;
        int l = 0, r = top - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (st[mid] < nxsm[i]) r = mid;
            else l = mid + 1;
        }
        nx[i] = st[l];
        // find maximum wihtin [i, nxsm[i])
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), nx[i] = 0;
        work();
        for (int i = 1; i <= n; i++)
            a[i] = n + 1 - a[i];
       // cout << "AF" << endl;
        work();
        // cout << "AF" << ' ' << n << endl;
        // for (int i = 1; i <= n; i++)
        //     cout << nx[i] << ' ';
        // cout << endl;
        int ans = 0;
        int pl = 1;
        while (pl != n) {
            pl = nx[pl];
            ans += 1;
        }
        cout << ans << endl;
    }
    return (0-0); //<3
}
/*
6
4 5 2 6 1 3
*/