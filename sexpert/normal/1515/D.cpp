#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    map<int, int> cnt;
    int saved = 0, tot = 0;
    for(int i = 0; i < l; i++) {
        int x;
        cin >> x;
        cnt[x]--;
    }
    for(int i = 0; i < r; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> le, ri;
    for(auto &[x, c] : cnt) {
        if(c == 0)
            continue;
        tot += abs(c);
        if(c < 0)
            le.push_back(-c);
        else
            ri.push_back(c);
    }
    int ole = 0, ori = 0, sle = 0, sri = 0, ans = tot/2;
    //cout << tot << '\n';
    for(auto &x : le) {
        if(x % 2)
            ole++;
        sle += x;
    }
    for(auto &x : ri) {
        if(x % 2)
            ori++;
        sri += x;
    }
    //cout << ole << " " << ori << " " << sle << " " << sri << '\n';
    if(ole <= ori)
        ans += (ori - min(ori, sle)) / 2;
    else
        ans += (ole - min(ole, sri)) / 2;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}