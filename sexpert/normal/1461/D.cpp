#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
ll A[MAXN];
set<ll> sums;
int n, q;

void calc(ll *st, ll *en) {
    if(st == en)
        return;
    ll mn = 1e9, mx = -1, sum = 0;
    //cout << "[";
    for(auto it = st; it != en; it++) {
        //cout << *it << " ";
        //cout.flush();
        mx = max(mx, *it);
        mn = min(mn, *it);
        sum += *it;
    }
    //cout << "]\n";
    sums.insert(sum);
    ll mid = (mn + mx)/2;
    auto f = [&](int x){ return x <= mid; };
    auto it = stable_partition(st, en, f);
    if(it != en)
        calc(st, it);
    if(it != st)
        calc(it, en);
}

void solve() {
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    sums.clear();
    calc(A, A + n);

    //cout << "Finished calc" << endl;
    //for(auto &s : sums)
    //    cout << s << " ";
    //cout << endl;
    while(q--) {
        ll s;
        cin >> s;
        cout << (sums.count(s) ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}