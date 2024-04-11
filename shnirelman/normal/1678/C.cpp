#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int LOGN = 30;

void upd(int i, int x, vector<int>& t) {
    for(; i < t.size(); i |= i + 1)
        t[i] += x;
}

int get(int i, vector<int>& t) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    li ans = 0;
    vector<int> pr(n, 0);
    for(int ib = 0; ib < n; ib++) {
        vector<int> suf(n, 0);
        for(int ic = n - 1; ic > ib; ic--) {
            ans += get(a[ib], suf) * get(a[ic], pr);
            upd(a[ic], 1, suf);
        }

        upd(a[ib], 1, pr);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}