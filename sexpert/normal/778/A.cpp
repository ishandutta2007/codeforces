#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> pos(n), good(n);
    for(auto &x : pos) {
        cin >> x;
        x--;
    }
    int lo = 0, hi = n;
    auto check = [&](int m) -> bool {
        if(m == 0)
            return true;
        fill(good.begin(), good.end(), 1);
        for(int i = 0; i < m; i++)
            good[pos[i]] = 0;
        int p = 0;
        for(int i = 0; i < n; i++) {
            if(!good[i])
                continue;
            if(s[i] == t[p])
                p++;
            if(p == t.size())
                break;
        }
        return (p == t.size());
    };
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}