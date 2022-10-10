#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());

    auto good = [&](int x) {
        if(x == 0)
            return true;
        int pt = n - 1;
        if(v[pt] <= v[x - 1])
            return false;
        for(int i = 0; i < x; i++) {
            if(v[pt - i - 1] <= v[x - i - 1])
                return false;
        }
        return true;
    };

    int lo = 0, hi = (n - 1)/2;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(good(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
    vector<int> ans(n);
    for(int i = 0; i < lo; i++)
        ans[2*i + 1] = v[i];
    for(int i = 0; i < lo + 1; i++)
        ans[2*i] = v[n - lo - 1 + i];
    for(int i = 2*lo + 1; i < n; i++)
        ans[i] = v[lo + (i - 2*lo - 1)];
    for(auto &x : ans)
        cout << x << " ";
    cout << '\n';
}