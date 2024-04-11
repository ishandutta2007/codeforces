#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v, cnt;
int n;

bool good(int L) {
    int take = n / (L + 1);
    int big = n % (L + 1), smol = n - big;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] > take + 1)
            return false;
        if(cnt[i] <= take && smol) {
            smol--;
            continue;
        }
        if(!big)
            return false;
        big--;
    }
    return true;
}

void solve() {
    cin >> n;
    v.resize(n);
    cnt.assign(n + 1, 0);
    for(auto &x : v) {
        cin >> x;
        cnt[x]++;
    }
    int lo = 0, hi = n - 1;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(good(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}