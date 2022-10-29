#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

template< class T >
T sqr(T x)
{
    return x * x;
}

typedef pair< int, int > pii;

typedef double ld;

ld dist(pii from, pii to)
{
    return sqrt(sqr(from.first - to.first) + sqr(from.second - to.second) + 0.);
}

ld
getAns(vector< pii > pnts)
{
    return dist(pnts[0], pnts[1]) + dist(pnts[1], pnts[2]) + dist(pnts[2], pnts[3]);
}

void
pushCand(vector< pii > &add, pii pnt, int n, int m)
{
    if (pnt.first >= 0 && pnt.first <= n && pnt.second >= 0 && pnt.second <= m) {
        add.push_back(pnt);
    }
}

int
main()
{
    int n, m;
    cin >> n >> m;
    vector< pii > cand;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            pushCand(cand, make_pair(i, j), n, m);
            pushCand(cand, make_pair(n - i, j), n, m);
            pushCand(cand, make_pair(i, m - j), n, m);
            pushCand(cand, make_pair(n - i, m - j), n, m);
        }
    }
    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
    int sz = int(cand.size());
    ld res = 0.;
    vector< pii > ans;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < sz; ++k) {
                for (int l = 0; l < sz; ++l) {
                    set< int > vals = {i, j, k, l};
                    if (vals.size() != 4) {
                        continue;
                    }
                    vector< pii > tmpC = {cand[i], cand[j], cand[k], cand[l]};
                    ld curV = getAns(tmpC);
                    if (curV > res + 1e-9) {
                        res = curV;
                        ans = tmpC;
                    }
                }
            }
        }
    }
    for (auto x : ans) {
        cout << x.first << " " << x.second << '\n';
    }
    return 0;
}