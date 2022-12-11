#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/*
int _n, i, j, k;
vector<int> seq;
int qc;
ll query(int l, int r) {
    printf("got ? %d %d\n", l, r);
    assert(1 <= l && l <= r && r <= _n);
    ++qc;
    ll ans = 0;
    for (int i = l; i < r; ++i) {
        for (int j = l - 1; j < i; ++j) {
            if (seq[j] > seq[i]) ++ans; 
        }
    }
    return ans;
}
void initialize() {
    printf("! RUNNING IN CHECK MODE\n");
    scanf("%d %d %d %d", &_n, &i, &j, &k);
    qc = 0;
    seq.assign(_n, 0);
    iota(begin(seq), end(seq), _n);
    reverse(begin(seq) + i - 1, begin(seq) + j - 1);
    reverse(begin(seq) + j - 1, begin(seq) + k);
}
void check(int _i, int _j, int _k) {
    if (qc > 40) {
        printf("[WA] Query limit exceeded\n");
        assert(false);
    } else if (i != _i || j != _j || k != _k) {
        printf("[WA] Expected %d %d %d, got %d %d %d\n", i, j, k, _i, _j, _k);
        assert(false);
    }
}
*/
ll query(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    ll x; scanf("%lld", &x);
    if (x == -1) exit(0);
    return x;
}



void solve() {
    int n; scanf("%d", &n);
//    initialize();
    // n = _n; printf("! Solving %d\n", n);
    ll totalInversion = query(1, n);
    ll lo = 1, hi = n;
//    printf("%lld total inversions\n", totalInversion);
    while (lo < hi) {
//        printf("qrange %lld %lld\n", lo, hi);
        ll mid = (lo + hi) / 2;
        if (query(1, mid) == totalInversion) hi = mid;
        else lo = mid + 1;
    }
    // lo is first index with totalInversion
    ll k = lo;
    ll invAddedAtK = query(1, k) - query(1, k - 1);
    ll j = k - invAddedAtK;
    ll i;
    if (j == 2) {
        i = 1;
    } else {
        ll invAddedBeforeJ = query(1, j - 1) - query(1, j - 2);
        i = j - 1 - (invAddedBeforeJ);
    }
    printf("! %lld %lld %lld\n", i, j, k);
    fflush(stdout);
//    check(i, j, k);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}