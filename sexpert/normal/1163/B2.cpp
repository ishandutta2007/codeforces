#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int cto = 0, cnt[MAX];

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    set<pair<int, int>> bct;
    for(int i = 0; i < n; i++) {
        int x = v[i];
        if(cnt[x] == 1) cto--;
        if(cnt[x] == 0) cto++;
        if(cnt[x] > 1) bct.erase({cnt[x], x});
        cnt[x]++;
        if(cnt[x] > 1) bct.insert({cnt[x], x});
        if(bct.empty()) {
            ans = i + 1;
            continue;
        }
        int mn = bct.begin()->first, mx = bct.rbegin()->first;
        if(mx == mn && cto == 1)
            ans = i + 1;
        if(!cto && mx == mn + 1 && mn * bct.size() == i)
            ans = i + 1;
        if(cto + bct.size() < 2)
            ans = i + 1;
        if(cto) {
            if(mx == 2 && bct.size() + cto == i)
                ans = i + 1;
        }
    }
    cout << ans << '\n';
}