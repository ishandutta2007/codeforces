#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int P = 1e4 + 7;
typedef unsigned long long ULL;

int n;
vector<int> e[N];

set<ULL> ext;

ULL f[N], power[N];
int size[N];

void dp1(int x, int fa) {
    vector<pair<ULL, int> > pr;
    for (auto &y : e[x]) {
        if (y == fa) continue;
        dp1(y, x);
        pr.push_back(make_pair(f[y], size[y]));
    }
    sort(pr.begin(), pr.end());
    f[x] = 'L';
    size[x] = 1;
    for (int i = 0; i < pr.size(); ++i) {
        f[x] = f[x] * power[pr[i].second] + pr[i].first;
        size[x] += pr[i].second;
    }
    ++size[x];
    f[x] = f[x] * P + 'R';
}

struct Point {
    ULL hash;
    int size;
    int x;

    int operator < (const Point &a) const {
        return make_pair(hash, size) < make_pair(a.hash, a.size);
    }
};

int bo[N], gs[N];
ULL g[N];
int degree[N];
map<ULL , int> cnt;
int res , cur;

void dp2(int x, int fa) {
    vector<Point> pr;
    for (auto &y : e[x]) {
        if (y == fa) pr.push_back((Point){g[x], gs[x], y});
        else pr.push_back((Point) {f[y], size[y], y});
    }
    sort(pr.begin(), pr.end());
    vector<ULL> sum;
    vector<int> sz;
    ULL tmp = 'L';
    sum.push_back(tmp);
    int tot = 2;
    for (int i = 0; i < pr.size(); ++i) {
        tmp = tmp * power[pr[i].size] + pr[i].hash;
        sum.push_back(tmp);
        tot += pr[i].size;
    }

    //ULL H = sum.back() * P + 'R';

    tmp = 'R';
    for (int i = (int)pr.size() - 1, sz = 1; i >= 0; --i) {
        int y = pr[i].x;
        if (y != fa) {
            g[y] = tmp;
            g[y] += sum[i] * power[sz];
            gs[y] = tot - pr[i].size;
            dp2(pr[i].x, x);

        }
        tmp += pr[i].hash * power[sz];
        sz += pr[i].size;
    }
}

void dp3(int x , int fa) {
    if (cnt.size() >= cur) {
        cur = cnt.size();
        res = x;
    }
    for (auto &y : e[x]) {
        if (y == fa) continue;
        if (!-- cnt[f[y]]) cnt.erase(f[y]);
        ++ cnt[g[y]];
        dp3(y , x);
        if (!-- cnt[g[y]]) cnt.erase(g[y]);
        ++ cnt[f[y]];
    }
}

int main() {
    scanf("%d", &n);
    power[0] = 1;
    for (int i = 1; i <= n ; ++i)
        power[i] = power[i - 1] * P;

    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dp1(1, 0);
    dp2(1, 0);

    for (int i = 2 ; i <= n ; ++ i) {
        ++ cnt[f[i]];
    }
    dp3(1 , 0);
    cout << res << endl;
    return 0;
}