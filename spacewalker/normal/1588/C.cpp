#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void mergesort(vector<ll> &src1, vector<ll> &src2, vector<ll> &dst) {
    int p1 = 0, p2 = 0;
    while (p1 < src1.size() && p2 < src2.size()) {
        if (src1[p1] < src2[p2]) dst.push_back(src1[p1++]);
        else dst.push_back(src2[p2++]);
    }
    dst.insert(end(dst), begin(src1) + p1, end(src1));
    dst.insert(end(dst), begin(src2) + p2, end(src2));
}

struct pathfinder {
    int al, ar;
    vector<ll> sup, sdown;
    pathfinder *left, *right;
    pathfinder() {}
    pathfinder(int i, int j, vector<ll> &arr) : al(i), ar(j), sup(), sdown(),
        left(nullptr), right(nullptr){
        if (i == j) {
            (i % 2 == 0 ? sup : sdown).push_back(arr[i]);
        } else {
            int k = (i + j) / 2;
            left = new pathfinder(i, k, arr);
            right = new pathfinder(k + 1, j, arr);
            mergesort(left->sup, right->sup, sup);
            mergesort(left->sdown, right->sdown, sdown);
        }
    }
    // misses CANNOT lie on the y line
    // also, i and i + 1 cannot be a miss
    int findEarliestMiss(int i, ll y) {
        if (ar < i) return -1;
        int ak = (al + ar) / 2;
        if (i > ak) return right->findEarliestMiss(i, y);
        if (al == ar) {
            if ((sdown.empty() && sup[0] < y)
                    || (sup.empty() && sdown[0] > y)) return al;
            else return -1;
        }
        if (i >= al) {
            int m = left->findEarliestMiss(i, y);
            if (m == -1) return right->findEarliestMiss(i, y);
            else return m;
        } else {
            // check if sup has some element < y, or if sdown has some element > y
            // if not, say -1; otherwise, recurse
            if (lower_bound(begin(sup), end(sup), y) == begin(sup) &&
                    upper_bound(begin(sdown), end(sdown), y) == end(sdown)) {
                return -1;
            } else {
                int m = left->findEarliestMiss(i, y);
                if (m == -1) return right->findEarliestMiss(i, y);
                else return m;
            }
        }
    }
    int countEqualTo(int i, int j, ll k) {
//        printf("CEQ %d %d %lld\n", i, j, k);
        if (ar < i || j < al) return 0;
        else if (i <= al && ar <= j) {
            ll bans = distance(lower_bound(begin(sup), end(sup), k), upper_bound(begin(sup), end(sup), k))
                + distance(lower_bound(begin(sdown), end(sdown), k), upper_bound(begin(sdown), end(sdown), k));
//            printf("base %ld %ld\n", distance(lower_bound(begin(sup), end(sup), k), upper_bound(begin(sup), end(sup), k)),
//                    distance(lower_bound(begin(sdown), end(sdown), k), upper_bound(begin(sdown), end(sdown), k)));
            return bans;
        } else {
            return left->countEqualTo(i, j, k) + right->countEqualTo(i, j, k);
        }
    }
};

bool solvable(vector<int> arr) {
    for (int &v : arr) v = abs(v);
    int n = arr.size();
    for (int i = 0; i + 1 < n; ++i) {
        if (arr[i] > 0 && arr[i+1] < arr[i]) return false;
        arr[i+1] -= arr[i];
        arr[i] = 0;
    }
    for (int i = 0; i < n; ++i) if (arr[i] != 0) return false;
    return true;
}

ll solve() {
    int n; scanf("%d", &n);
    vector<ll> arr(n); for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    for (int i = 1; i < n; i += 2) arr[i] *= -1; // odd <=> downstroke
    vector<ll> pfsum(n + 1);
    for (int i = 0; i < n; ++i) pfsum[i+1] = pfsum[i] + arr[i];
    vector<ll> pfsum_trunc(begin(pfsum) + 1, end(pfsum));
    pathfinder pf(0, n - 1, pfsum_trunc);
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int j = pf.findEarliestMiss(i, pfsum[i]);
//        printf("%d fem %d\n", i, j);
        if (j == -1) j = n + 1;
        ll ccontrib = pf.countEqualTo(i, j - 2, pfsum[i]);
        
        /* brute force check
//        printf("bfcheck %d\n", i);
        ll bcontrib = 0; 
        for (int j = i; j < n; ++j) {
            vector<int> sarr(begin(arr) + i, begin(arr) + j + 1);
            if (solvable(sarr)) {
//                printf("solvable %d %d\n", i, j);
                ++bcontrib;
            }
        }
        assert(bcontrib == ccontrib);
        */
        ans += ccontrib;
    }
    if (arr[n-1] == 0) ++ans;
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%lld\n", solve());
    }
}