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
const int maxn = 2005;
struct pt {
    int a, b;
    pt(){a = 0, b = 0;}
    pt(int x, int y) {
        a = x, b = y;
    }
    pt operator - (pt u) { 
        return pt(a - u.a, b - u.b);
    }
    ll operator * (pt v) {
        return 1ll * a * v.b - 1ll * b * v.a;
    }
}h[maxn];

bool cmp(int a, int b) {
    return h[a] * h[b] > 0;
}
int p[maxn];
vector<pi> res;
void act(int u, int v) {
    res.pb(mp(u, v));
    swap(p[u], p[v]);
}
int rh(int u, int v) {
    int s = v;
    while (1) {
        if (s == u) return 1;
        s = p[s];
        if (s == v) break;
    }
    return 0;
}
int main() {
    vi cur;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &h[i].a, &h[i].b, &p[i]);
        if (p[i] != i) cur.pb(i);
    }
    for (auto v : cur) {
        int mn = 0;
        for (auto s : cur) {
            if (s != v)
                h[s] = h[s] - h[v];
        }
        h[v] = pt(0, 0);
        for (auto s : cur) {
            if (s == v) continue;
            if (mn == 0) mn = s;
            else if (h[mn] * h[s] <= 0) mn = s;
        }
        int flag = 1;
        for (auto s : cur) {
            if (s == v) continue;
            if (h[mn] * h[s] < 0) flag = 0;
        }
        if (!flag) continue;
        vi cr;
        for (auto s : cur) {
            if (s == v) continue;
            cr.pb(s);
        }
        //cout << "!!!" << endl;
        sort(cr.begin(), cr.end(), cmp);
        for (int i = 0; i < cr.size() - 1; i++)
            if (!rh(cr[i], cr[i + 1])) act(cr[i], cr[i + 1]);
        while (p[v] != v) 
            act(v, p[v]);
        break;
    }
    cout << res.size() << endl;
    for (auto s : res)
        printf("%d %d\n", s.fi, s.se);
    return 0;
}