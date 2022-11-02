#include <bits/stdc++.h>

using namespace std;



#define N 100005

#define x first

#define y second

#define M 1000000



typedef long long ll;

const ll mx = 1e12;



struct pnt{

    int x, y;

    pnt (int x = 0, int y = 0) : x(x), y(y) {}

    pnt operator+ (const pnt &_) const {

        return pnt(x + _.x, y + _.y);

    }

    pnt operator- (const pnt &_) const {

        return pnt(x - _.x, y - _.y);

    }

    ll dist() {

        return 1ll * x * x + 1ll * y * y;

    }

} o = pnt(0, 0);

pnt p[N];

int n;

int rt[N], sgn[N];

pnt sum[N];

set<int> rts;

set<int> :: iterator it;



bool trim(int x, int y) {

    if ((sum[x] + sum[y]).dist() <= mx) {

        rt[x] = y;

        sgn[x] = 1;

        sum[y] = sum[y] + sum[x];

        rts.erase(x);

        return 1;

    }

    if ((sum[x] - sum[y]).dist() <= mx) {

        rt[y] = x;

        sgn[y] = -1;

        sum[x] = sum[x] - sum[y];

        rts.erase(y);

        return 1;

    }

    return 0;

}



vector<int> v[N];

int ans[N];



void dfs(int x, int par = 0) {

    ans[x] = ans[par] * sgn[x];

    for (int i = 0; i < v[x].size(); i ++) {

        int y = v[x][i];

        dfs(y, x);

    }

}



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {

        scanf("%d %d", &p[i].x, &p[i].y);

        rt[i] = i;

        sgn[i] = 1;

        sum[i] = p[i];

        rts.insert(i);

    }

    while (rts.size() > 2) {

        it = rts.begin();

        int x = *it, y = *(++it), z = *(++it);

        if (trim(x, y)) { continue; }

        if (trim(y, z)) continue;

        if (trim(x, z)) continue;

    }

    if (rts.size() == 2) {

        it = rts.begin();

        int x = *it, y = *(++it);

        trim(x, y);

    }

    for (int i = 1; i <= n; i ++) {

        if (rt[i] != i) v[rt[i]].push_back(i);

    }

    it = rts.begin();

    ans[0] = 1;

    dfs(*it);

    pnt s1 = sum[*it];

    if (rts.size() == 2) {

        it ++;

        pnt s2 = sum[*it];

        if ((s1 + s2).dist() <= 2250000000000ll) ans[0] = 1;

        else ans[0] = -1;

        dfs(*(it));

    }

    for (int i = 1; i <= n; i ++) {

        printf("%d ", ans[i]);

    }

    return 0;

}