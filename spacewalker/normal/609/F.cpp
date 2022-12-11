#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int INF = 1000000000;

// find min i st. a[i] >= v
// set a[i]
struct DepressionTree {
    int al, ar;
    DepressionTree *left, *right;
    ll rmax;
    DepressionTree(int i, int j) : al(i), ar(j), left(nullptr), right(nullptr), rmax(0) {
        if (i != j) {
            int k = (i + j) / 2;
            left = new DepressionTree(i, k);
            right = new DepressionTree(k + 1, j);
        }
    }
    void setValue(int i, ll v) {
        if (ar < i || i < al) return;
        else if (al == ar) rmax = v;
        else {
            left->setValue(i, v); right->setValue(i, v);
            rmax = max(left->rmax, right->rmax);
        }
    }
    int getFirstGEQ(ll v) {
        if (v > rmax) return INF;
        else if (al == ar) return al;
        else if (left->rmax >= v) return left->getFirstGEQ(v);
        else return right->getFirstGEQ(v);
    }
};

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<pair<ll, ll>> frogs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &frogs[i].first, &frogs[i].second);
    }
    vector<int> frogOrder(n);
    iota(begin(frogOrder), end(frogOrder), 0);
    sort(begin(frogOrder), end(frogOrder), [&] (int i, int j) {
        return frogs[i].first < frogs[j].first;
    });
    vector<ll> mosquitoesEaten(n), curLength(n);
    vector<int> frogPositions(n);
    for (int i = 0; i < n; ++i) {
        frogPositions[i] = frogs[frogOrder[i]].first;
        curLength[i] = frogs[frogOrder[i]].second;
    }
    auto cRightReach = [&] (int i) {
        return curLength[i] + frogPositions[i];
    };
    DepressionTree rightBoundary(0, n-1);
    for (int i = 0; i < n; ++i) rightBoundary.setValue(i, cRightReach(i));
    multiset<pair<int, int>> uneatenBois;
    for (int qta = 0; qta < m; ++qta) {
        ll pos, size; scanf("%lld %lld", &pos, &size);
        uneatenBois.emplace(pos, size);
        while (!uneatenBois.empty() && uneatenBois.lower_bound(make_pair(pos, -1)) != uneatenBois.end()) {
            tie(pos, size) = *uneatenBois.lower_bound(make_pair(pos, -1));
            int guyWhoEats = rightBoundary.getFirstGEQ(pos); // try to compute this
            /*
            if (qta == 8) {
                printf("checking if someone will eat %lld %lld\n", pos, size);
                printf("that will be %d\n", guyWhoEats);
                if (guyWhoEats < INF) printf("candidate is at %d %lld\n", frogPositions[guyWhoEats], frogPositions[guyWhoEats] 
                        + curLength[guyWhoEats]);
            }
            */
            if (guyWhoEats == INF || frogPositions[guyWhoEats] > pos) guyWhoEats = -1; 
            if (guyWhoEats == -1) break;
            else {
                curLength[guyWhoEats] += size;
                ++mosquitoesEaten[guyWhoEats];
                rightBoundary.setValue(guyWhoEats, cRightReach(guyWhoEats));
                uneatenBois.erase(uneatenBois.find(make_pair(pos, size)));
            }
        }
    }
    vector<int> posInSort(n);
    for (int i = 0; i < n; ++i) posInSort[frogOrder[i]] = i;
    for (int i = 0; i < n; ++i) {
        printf("%lld %lld\n", mosquitoesEaten[posInSort[i]], curLength[posInSort[i]]); 
    }
    return 0;
}