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
const int maxn = 1000005;
vector<pair<int, vi> > res;
vi ids;
void pushone(int mask, int tp) {
    vi cur;
    for (int j = 0; j < ids.size(); j++)
        if (mask & (1 << j))    cur.pb(ids[j]);
    res.pb(mp(tp, cur));
}
int sgn(int x) {
    if (x > 0) return 0;
    return 1;
}
void push(int msk, int tot) {
    for (int j = 0; j < abs(tot); j++)
        pushone(msk, sgn(tot)); 
}
int w[maxn];
int tw[maxn];
void work() {
    int tot = 1 << ids.size();
    for (int j = 1; j < tot; j++) {
        int nw = 0;
        for (int k = j; k; k = (k - 1) & j)
            nw += w[k];
        int nd = 0;
        if (__builtin_popcount(j) == 1) nd = 1;
        w[j] = nd - nw;
    }
    for (int j = 1; j < tot; j++) {
        w[j] *= -1;
        if (__builtin_popcount(j) & 1) 
            w[j] += 2;
        else w[j] -= 2;
        tw[j] += w[j];
    }
    for (int j = 1; j < tot; j++)
        push(j, tw[j]);
}
int bpr[maxn];
vector<pi> prs[maxn];
int a[maxn];
vi sons[maxn];
int rd() {
    return (rand() & 32767) * 32768 + rand();
}
int main() {
    for (int i = 1; i < maxn; i++)
        bpr[i] = 1;
    int msz = 0;
    for (int j = 2; j < maxn; j++) {
        if (bpr[j]) {
            for (int k = j ; k < maxn;  k += j) {
                sons[k].pb(j);
                if (k > j) bpr[k] = 0;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int cur = a[i];
        for (auto v : sons[cur]) {
            int t = 0;
            int cr = cur;
            while (cr % v == 0) 
                cr /= v, t += 1;
            prs[v].pb(mp(t, i));
        }     
    }
    for (int i = 2; i < maxn; i++) {
        if (!bpr[i])
            continue;
        if (prs[i].size() < n / 2) continue;
        for (int j = 1; j <= n; j++)
            if (a[j] % i)
                prs[i].pb(mp(0, j));
        sort(prs[i].begin(), prs[i].end());
        ids.pb(prs[i][0].se);
        ids.pb(prs[i][1].se);
    }
    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    while (ids.size() < 14 && ids.size() < n) {
        ids.pb(rd() % n + 1);

        sort(ids.begin(), ids.end());
        ids.erase(unique(ids.begin(), ids.end()), ids.end());
    }
    work();
    cout << res.size() << endl;
    for (auto v : res) {
        printf("%d %d ", v.fi, v.se.size());
        for (auto h : v.se)
            printf("%d ", h);
        printf("\n");
    }
    return (0-0); //<3
}