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
void otp(vi a) {
    for (auto v : a) cout << v << ' ';
    cout << endl;
}
const int maxn = 200005;
int a[maxn];
int n;
int minl[maxn];
int lmin[maxn];
int lstless[maxn];
void work() {
    vector<pi> h;
    for (int i = 1; i <= n; i++)
        h.pb(mp(a[i], i)), lstless[i] = 0;
    sort(h.begin(), h.end());
    set<int> cur;
    for (auto v : h) {
        int pl = v.se; 
        lstless[pl] = 0;
        auto ls = cur.lower_bound(pl);
        if (ls != cur.begin()) {
            ls--;
            lstless[pl] = *ls;
        }
        cur.insert(pl);
    }
    cur.clear();
    reverse(h.begin(), h.end());
    set<int> bads; // place where x[i] < next
    set<int> index;
    auto recalc = [&](int id) {
        if (bads.find(id) != bads.end())
            bads.erase(id);
        auto nx = index.lower_bound(id + 1);
        if (nx == index.end()) return ;
        int nextind = *nx;
        if (a[id] < a[nextind])
            bads.insert(id);
    };
    for (auto v : h) {
        int id = v.se;
        index.insert(id);
        recalc(id);
        auto last = index.lower_bound(id);
        if (last != index.begin()) {
            last--;
            recalc(*last);
        }
        minl[id] = 1;
        if (lstless[id]) {
            auto pl = index.lower_bound(lstless[id]);
            if (pl != index.begin()) {
                pl--;
                int maxr = *pl;
                auto place = bads.lower_bound(maxr);
                if (place != bads.begin()) {
                    place--;
                    minl[id] = (*place) + 1;
                }
            }
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    work();
    for (int i = 1; i <= n; i++)
        lmin[i] = minl[i], minl[i] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = n + 1 - a[i];
    work();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        chkmax(lmin[i], minl[i]);
        chkmax(lmin[i], 1);
    }
    for (int i = 1; i <= n; i++) 
        chkmax(lmin[i], lmin[i - 1]);
    for (int i = 1; i <= n; i++) 
        ans += i - lmin[i] + 1;
    cout << ans << endl;
    return (0-0); //<3
}
/*
6
4 5 2 6 1 3
*/