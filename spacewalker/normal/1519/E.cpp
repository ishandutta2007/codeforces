#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using fraction = pair<ll, ll>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

fraction simplify(fraction a) {
    ll g = gcd(a.first, a.second);
    return fraction(a.first / g, a.second / g);
}

fraction operator + (fraction a, fraction b) {
    return fraction(a.first * b.second + a.second * b.first, a.second * b.second);
}

fraction operator / (fraction a, fraction b) {
    return fraction(a.first * b.second, a.second * b.first);
}

vector<pair<int, int>> ans;
vector<bool> buhay, nabisita;
vector<vector<pair<int, int>>> graph;

int ppop(vector<int> &v) {
    int res = v.back(); v.pop_back();
    return res;
}

void patayin(int a, int b) {
    buhay[a] = buhay[b] = false;
    ans.emplace_back(a, b);
}

void order66(vector<int> &v) {
    while (v.size() >= 2) {
        int a = ppop(v);
        int b = ppop(v);
        patayin(a, b);
    }
}


// return code: true iff still connected with parent
bool ihave777(int v, int etp) {
//    printf("visit %d\n", v);
    nabisita[v] = true;
    vector<int> edgeSaLikod, batangEdge;
    for (auto [c, eid] : graph[v]) {
        if (!buhay[eid] || eid == etp) continue;
        if (nabisita[c]) edgeSaLikod.push_back(eid);
        else {
            if (ihave777(c, eid)) batangEdge.push_back(eid);
        }
    }
    // start by deleting back edges
    order66(edgeSaLikod);
    order66(batangEdge);
    vector<int> natitira;
    if (etp != -1) natitira.push_back(etp);
    if (batangEdge.size() > 0) natitira.push_back(batangEdge[0]);
    if (edgeSaLikod.size() > 0) natitira.push_back(edgeSaLikod[0]);
//    printf("natitira kay %d:", v);
//    for (int c : natitira) printf(" %d", c);
//    printf("\n");
    order66(natitira);
    return (etp == -1 ? false : buhay[etp]);
}

int main() {
    int n; scanf("%d", &n);
    vector<fraction> xps(n), yps(n);
    for (int i = 0; i < n; ++i) scanf("%lld %lld %lld %lld", &xps[i].first, &xps[i].second, &yps[i].first, &yps[i].second);
    vector<fraction> upslope(n), rightslope(n);
    vector<fraction> slopes(2 * n);
    for (int i = 0; i < n; ++i) {
        slopes[i] = rightslope[i] = simplify(yps[i] / (xps[i] + fraction(1, 1)));
        slopes[i + n] = upslope[i] = simplify((yps[i] + fraction(1, 1)) / xps[i]);
    }
    sort(begin(slopes), end(slopes));
    slopes.erase(unique(begin(slopes), end(slopes)), end(slopes));
    auto fcomp = [&] (fraction f) {
        return distance(begin(slopes), lower_bound(begin(slopes), end(slopes), f));
    };
    int gn = slopes.size();
    graph.assign(gn, vector<pair<int, int>>());
//    printf("REDUCED TO n = %d\n", gn);
    for (int i = 0; i < n; ++i) {
        int u = fcomp(upslope[i]), v = fcomp(rightslope[i]);
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
//        printf("%d - %d\n", u, v);
    }
    buhay.assign(n, true);
    nabisita.assign(gn, false);
    for (int i = 0; i < gn; ++i) if (!nabisita[i]) ihave777(i, -1);
    printf("%lu\n", ans.size());
    for (auto [a, b] : ans) printf("%d %d\n", a + 1, b + 1);
}