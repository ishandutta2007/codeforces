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
const int maxn = 1000005;
bool bpr[maxn];
int a[maxn];
ll cal(vi a) {
    ll tot = 0;
    for (int i = 0; i < 2; i++) {
        ll na = 0;
        int pl = 0, sm = 0;
        for (int j = 0; j < a.size(); j++) {
            sm += a[j];
            while (pl <= j && sm > i)
                sm -= a[pl], pl += 1;
            if (j > pl) na += j - pl;
        }
        if (i == 0) tot -= na;
        else tot += na;
    }
    return tot;
}

int main() {
    for (int i = 0; i < maxn; i++)
        bpr[i] = 1;
    for (int i = 2; i < maxn; i++) {
        if (bpr[i])
            for (int j = 2 * i; j < maxn; j += i)
                bpr[j] = 0;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            int s = 0;
            if (a[i] == 1) s = 0;
            else if (bpr[a[i]]) s = 1;
            else s = 2;
            a[i] = s;
        }
        ll ans = 0;
        for (int i = 1; i <= e; i++) {
            vi cur;
            for (int j = i; j <= n; j += e)
                cur.pb(a[j]);
            ans += cal(cur);
        }
        cout << ans << endl;
    }
    return (0-0); //<3
}