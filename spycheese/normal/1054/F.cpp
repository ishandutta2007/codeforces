#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 1011;

struct Line {
    vector<int> cs;
    int si0;
};

struct Seg {
    int x, y1, y2;
};

int vc1, vc2;
Seg vs1[N], vs2[N];
vector<int> e[N];
int p2[N];
int p1[N];
bool vis1[N];
bool ok1[N], ok2[N];

bool dfs(int v) {
    if (vis1[v])
        return false;
    vis1[v] = true;
    for (int nv : e[v]) {
        if (p2[nv] == -1) {
            p2[nv] = v;
            p1[v] = nv;
            return true;
        } else if (dfs(p2[nv])) {
            p2[nv] = v;
            p1[v] = nv;
            return true;
        }
    }
    return false;
}

void dfs2(int v) {
    if (vis1[v])
        return;
    vis1[v] = 1;
    for (int nv : e[v])
        if (p2[nv] != -1)
            dfs2(p2[nv]);
}

int main() {
    memset(p1, -1, sizeof(p1));
    memset(p2, -1, sizeof(p2));
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    map<int, Line> mx, my;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        mx[x].cs.push_back(y);
        my[y].cs.push_back(x);
    }

    for (auto& p : mx) {
        int x = p.X;
        Line &l = p.Y;
        sort(all(l.cs));
        l.si0 = vc1;
        for (int i = 0; i < sz(l.cs) - 1; ++i)
            vs1[vc1++] = {x, l.cs[i], l.cs[i+1]};
    }
    for (auto& p : my) {
        int y = p.X;
        Line &l = p.Y;
        sort(all(l.cs));
        l.si0 = vc2;
        for (int i = 0; i < sz(l.cs) - 1; ++i)
            vs2[vc2++] = {y, l.cs[i], l.cs[i+1]};
    }

    for (int i = 0; i < vc1; ++i)
        for (int j = 0; j < vc2; ++j) {
            Seg s1 = vs1[i];
            Seg s2 = vs2[j];
            if (s1.y1 < s2.x && s2.x < s1.y2)
                if (s2.y1 < s1.x && s1.x < s2.y2) {
                    e[i].push_back(j);
                }
        }

    while (true) {
        bool was = false;
        memset(vis1, 0, sizeof(bool) * vc1);
        for (int i = 0; i < vc1; ++i)
            if (p1[i] == -1 && dfs(i))
                was = true;
        if (!was)
            break;
    }

    memset(vis1, 0, sizeof(bool) * vc1);
    for (int i = 0; i < vc1; ++i)
        if (p1[i] == -1)
            dfs2(i);
    for (int i = 0; i < vc1; ++i)
        if (vis1[i])
            ok1[i] = 1;
    for (int i = 0; i < vc2; ++i)
        if (p2[i] == -1 || !vis1[p2[i]])
            ok2[i] = 1;

    struct Ans {
        int x1, y1, x2, y2;
    };
    vector<Ans> ans;

    for (auto const& p : my) {
        int y = p.X;
        Line const& l = p.Y;
        int i = 0;
        while (i < sz(l.cs)) {
            int j = i;
            while (j < sz(l.cs) - 1) {
                int id = l.si0 + j;
                if (ok2[id])
                    ++j;
                else
                    break;
            }
            ans.push_back({l.cs[i], y, l.cs[j], y});
            i = j + 1;
        }
    }
    cout << sz(ans) << "\n";
    for (auto s : ans)
        cout << s.x1 << " " << s.y1 << " " << s.x2 << " " << s.y2 << "\n";
    ans.clear();
    for (auto const& p : mx) {
        int x = p.X;
        Line const& l = p.Y;
        int i = 0;
        while (i < sz(l.cs)) {
            int j = i;
            while (j < sz(l.cs) - 1) {
                int id = l.si0 + j;
                if (ok1[id])
                    ++j;
                else
                    break;
            }
            ans.push_back({x, l.cs[i], x, l.cs[j]});
            i = j + 1;
        }
    }
    cout << sz(ans) << "\n";
    for (auto s : ans)
        cout << s.x1 << " " << s.y1 << " " << s.x2 << " " << s.y2 << "\n";

    return 0;
}