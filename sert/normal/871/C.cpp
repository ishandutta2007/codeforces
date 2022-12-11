#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;
const ll md = (ll)1e9 + 7;

struct pt {
    int x, y, n;
    pt() {}
    pt(int xx, int yy, int nn) {
        x = xx;
        y = yy;
        n = nn;
    }
    bool operator != (const pt &a) const {
        return x != a.x || y != a.y;
    }
};

unordered_map <int, vector<int> > xx, yy;
bool u[N];
unordered_map <int, int> cx, cy;
int cnt = 1;

ll ans = 1;
bool cyc;
ll st2[N];
pt a[N];
int vv;
int ee;

void dfs(int v) {
    if (u[v]) return;
    u[v] = true;
    vv++;
    pt p = a[v];

    //cerr << p.x << " " << p.y << " " << v << "\n";

    if (cx[p.x] == cnt) {
        cyc = true;
    } else {
        ee++;
        cx[p.x] = cnt;
        for (auto w: xx[p.x])
            dfs(w);
    }

    if (cy[p.y] == cnt) {
        cyc = true;
    } else {
        ee++;
        cy[p.y] = cnt;
        for (auto w: yy[p.y])
            dfs(w);
    }
}

int main() {
    init();

    st2[0] = 1;
    for (int i = 1; i < N; i++) {
        st2[i] = (st2[i - 1] * 2) % md;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].n = i;
        scanf("%d%d", &a[i].x, &a[i].y);
        xx[a[i].x].push_back(i);
        yy[a[i].y].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        vv = ee = 0;
        cyc = false;
        cnt++;
        //cerr << "dfs " << i << "\n";
        dfs(i);
        //cerr << "sz = " << sz << "\n";
        ans = (ans * (st2[ee] - (vv >= ee ? 0 : 1) + md)) % md;
    }

    cout << ans;

    return 0;
}