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
const int maxn = 205;
int n;
int p[maxn];
int fl[maxn];
vi mg(vi a, vi b, int k) {
    int p[2];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == k)  p[0] = i;
    }
    for (int i = 0; i < b.size(); i++)
        if (b[i] == k + 1)
            p[1] = i;
    //cout << p[0] << ' ' << p[1] << endl;
    vi res;
    for (int i = 0; i + 1 < a.size(); i++)
        res.pb(a[(p[0] + 1 + i) % a.size()]);
    for (int i = 0; i < b.size(); i++)
        res.pb(b[(p[1] + i) % b.size()]);
    res.pb(k);
    return res;
}
vi fd(int x) {
    vi res;
    while (1) {
        res.pb(x); fl[x] = 1;
        //cout << x << ' ' << p[x] << endl;
        x = p[x];
        if (fl[x]) break;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
   //cout << "AA" << endl;
    while (t--) {
        cin >> n;
        memset(fl, 0, sizeof(fl));
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        vi cur = fd(1);
        for (int i = 2; i <= n; i++) {
            if (fl[i]) continue;
            else {
                vi h = fd(i);
                cur = mg(cur, h, i - 1);
            }
        }
        reverse(cur.begin(), cur.end());
        for (int i = 0; i < n; i++)
            cout << cur[i] << " ";
    }
    return (0-0); //<3
}