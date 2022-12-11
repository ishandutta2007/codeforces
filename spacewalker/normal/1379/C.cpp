#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct overkill {
    int al, ar;
    ll rtotal; int rcount;
    overkill *left, *right;
    overkill(int i, int j, vector<int> &pts) : al(pts[i]), ar(pts[j]), rtotal(0), rcount(0),
        left(nullptr), right(nullptr) {
        if (i != j) {
            int k = (i + j) / 2;
            left = new overkill(i, k, pts);
            right = new overkill(k + 1, j, pts);
        }
    }
    void addPoint(int i) {
        if (ar < i || i < al) return;
        else if (al == ar) {
            rtotal += al;
            ++rcount;
        } else {
            left->addPoint(i);
            right->addPoint(i);
            rtotal = left->rtotal + right->rtotal;
            rcount = left->rcount + right->rcount;
        }
    }
    int countRange(int i, int j) {
//        printf("cr %d %d %d %d\n", i, j, al, ar);
        if (j < al || ar < i) return 0;
        else if (i <= al && ar <= j) return rcount;
        else return left->countRange(i, j) + right->countRange(i, j);
    }
    ll getHighestKSum(int k) {
        if (al == ar) return min(k, rcount) * (ll)al;
        else if (rcount == k) return rtotal;
        else if (right->rcount >= k) return right->getHighestKSum(k);
        else return right->getHighestKSum(right->rcount)
            + left->getHighestKSum(k - right->rcount);
    }
};

ll solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<pair<int, int>> f(m); // stores {b, a}
    for (int i = 0; i < m; ++i) scanf("%d %d", &f[i].second, &f[i].first);
    sort(begin(f), end(f));
    ll ans = 0;
    vector<int> b_unique;
    for (auto [b, a] : f) {
        b_unique.push_back(b);
        b_unique.push_back(a);
    }
    sort(begin(b_unique), end(b_unique)); b_unique.erase(unique(begin(b_unique), end(b_unique)), end(b_unique));
    overkill smash(0, b_unique.size() - 1, b_unique);
    for (int i = 0; i < m; ++i) {
        int exc = n - 1;
        int pbtake = min(smash.countRange(f[i].first, b_unique.back()), exc);
        ll cans = f[i].second + smash.getHighestKSum(pbtake);
//        printf("%d %d cans %lld pbt %d\n", f[i].second, f[i].first, cans, pbtake);
        if (pbtake < exc) cans += (ll)f[i].first * (exc - pbtake);
        ans = max(ans, cans);
//        printf("%d %d cans %lld\n", f[i].second, f[i].first, cans);
        smash.addPoint(f[i].second);
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%lld\n", solve());
}