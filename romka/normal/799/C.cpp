#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sqr(x) (x) * (x)
template <class T> ostream& operator<<(ostream& out, const vector<T>& v) { forn(i, v.size()) { if (i) out << " "; out << v[i]; } return out; }
template <class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) { out << "{" << p.first << ", " << p.second << "}"; return out; }

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;

int getans(const vector<pii>& v, const vector<int>& m, int cp, int mx) {
    int res = 0;
    for (int j = cp; j > 0; j--) {
        int extra = mx - v[j].first;
        int ip = lower_bound(v.begin(), v.begin() + j, pii(extra, inf)) - v.begin();
        if (ip > 0) res = max(res, m[ip - 1] + v[j].second);
    }
    return res;
}

int main() {
    int n, c, d, x, val;
    char buf[8];
    scanf("%d %d %d", &n, &c, &d);
    vector<pii> vc, vd;
    forn(i, n) {
        scanf("%d %d %s", &val, &x, buf);
        if (buf[0] == 'C') vc.emplace_back(x, val);
        else vd.emplace_back(x, val);
    }

    sort(vc.begin(), vc.end());
    sort(vd.begin(), vd.end());

    vector<int> mc(vc.size()), md(vd.size());

    if (!vc.empty()) {
        mc[0] = vc[0].second;
        for (size_t i = 1; i < vc.size(); i++)
            mc[i] = max(mc[i-1], vc[i].second);
    }
    if (!vd.empty()) {
        md[0] = vd[0].second;
        for (size_t i = 1; i < vd.size(); i++)
            md[i] = max(md[i-1], vd[i].second);
    }

    int ans = 0;
    int ic = lower_bound(vc.begin(), vc.end(), pii(c, inf)) - vc.begin();
    int id = lower_bound(vd.begin(), vd.end(), pii(d, inf)) - vd.begin();
    if (ic > 0 && id > 0) ans = mc[ic - 1] + md[id - 1];

    if (ic > 0)
        ans = max(ans, getans(vc, mc, ic - 1, c));
    if (id > 0)
        ans = max(ans, getans(vd, md, id - 1, d));

    printf("%d\n", ans);
    return 0;
}