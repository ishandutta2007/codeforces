#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 1005;
ll xx[MAXN], yy[MAXN], rep[MAXN], n, nc;
vector<ll> xs, ys;
map<ll, ll> cx, cy;
vector<ii> byx[MAXN], byy[MAXN];
array<ll, 4> nei[MAXN][MAXN];
int lol[MAXN];

const ll INF = 2e9 + 10;
const ll BIG = 1e9;

int find(int u) {
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    rep[v] = u;
    nc--;
}

bool cock(ll t) {
    iota(rep, rep + MAXN, 0);
    nc = n;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(xx[i] != xx[j] && yy[i] != yy[j])
                continue;
            if(abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]) <= t)
                join(i, j);
        }
    }

    if(nc >= 5)
        return false;

    if(nc == 1)
        return true;

    map<ll, ll> rps;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int x = find(i);
        if(!rps.count(x))
            rps[x] = cur++;
    }

    for(int x = 0; x < xs.size(); x++) {
        for(int y = 0; y < ys.size(); y++) {
            int ms = 0;
            for(auto &i : nei[x][y]) {
                if(i == -1)
                    continue;
                if(abs((ll)xx[i] - (ll)xs[x]) + abs((ll)yy[i] - (ll)ys[y]) <= (ll)t)
                    ms |= (1 << rps[find(i)]);
            }
            if(ms == (1 << nc) - 1)
                return true;
        }
    }

    if(nc > 2)
        return false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(xx[i] != xx[j] && yy[i] != yy[j])
                continue;
            if(find(i) == find(j))
                continue;
            if(abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]) <= 2*t)
                return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> xx[i] >> yy[i];
        xs.push_back(xx[i]);
        ys.push_back(yy[i]);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int cur = 0;
    for(auto &x : xs)
        cx[x] = cur++;
    cur = 0;
    for(auto &y : ys)
        cy[y] = cur++;

    for(int i = 0; i < n; i++) {
        byx[cx[xx[i]]].push_back({cy[yy[i]], i});
        byy[cy[yy[i]]].push_back({cx[xx[i]], i});
    }

    for(int i = 0; i < xs.size(); i++)
        sort(byx[i].begin(), byx[i].end());

    for(int i = 0; i < ys.size(); i++)
        sort(byy[i].begin(), byy[i].end());

    for(int i = 0; i < xs.size(); i++) {
        for(int j = 0; j < ys.size(); j++) {
            nei[i][j] = {-1, -1, -1, -1};
        }
    }

    for(int x = 0; x < xs.size(); x++) {
        auto &vc = byx[x];
        if(vc.empty())
            continue;
        int p = 0;
        for(int y = 0; y < ys.size(); y++) {
            if(y < vc[0][0])
                continue;
            while(p + 1 < vc.size() && vc[p + 1][0] <= y)
                p++;
            if(vc[p][0] == y)
                continue;
            nei[x][y][0] = vc[p][1];
        }
        p = vc.size() - 1;
        for(int y = ys.size() - 1; y >= 0; y--) {
            if(y > vc[vc.size() - 1][0])
                continue;
            while(p - 1 >= 0 && vc[p - 1][0] >= y)
                p--;
            if(vc[p][0] == y)
                continue;
            nei[x][y][1] = vc[p][1];
        }
    }

    for(int y = 0; y < ys.size(); y++) {
        auto &vc = byy[y];
        if(vc.empty())
            continue;
        int p = 0;
        for(int x = 0; x < xs.size(); x++) {
            if(x < vc[0][0])
                continue;
            while(p + 1 < vc.size() && vc[p + 1][0] <= x)
                p++;
            if(vc[p][0] == x)
                continue;
            nei[x][y][2] = vc[p][1];
        }
        p = vc.size() - 1;
        for(int x = xs.size() - 1; x >= 0; x--) {
            if(x > vc[vc.size() - 1][0])
                continue;
            while(p - 1 >= 0 && vc[p - 1][0] >= x)
                p--;
            if(vc[p][0] == x)
                continue;
            nei[x][y][3] = vc[p][1];
        }
    }

    /*for(int x = 0; x < xs.size(); x++) {
        for(int y = 0; y < ys.size(); y++) {
            auto &[a, b, c, d] = nei[x][y];
            cout << "(" << x << " " << y << ") " << "(" << xs[x] << " " << ys[y] << ") " << a << " " << b << " " << c << " " << d << '\n';
        }
    }*/

    if(!cock(INF)) {
        cout << "-1\n";
        return 0;
    }

    ll lo = 0, hi = INF;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(cock(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    
    lol[25] = 10;

    cout << lo << '\n';
}