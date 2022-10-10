#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    vector<int> uwu;
    bool done = false;
    int step = 0;
    while(!done) {
        step++;
        vector<int> ps;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 0)
                ps.push_back(i);
        }
        if(ps.empty()) {
            done = true;
            break;
        }
        uwu.push_back(ps.size());
        vector<int> tmp(v.size());
        for(int i = 0; i < v.size(); i++) {
            if(v[i] < 0) {
                tmp[i] = v[i];
                continue;
            }
            if(v[i] == 0) {
                tmp[i] = -step;
                continue;
            }
            int x = v[i];
            for(auto idx : ps)
                x -= abs(i - idx);
            tmp[i] = x;
        }
        v = tmp;
    }
    vector<int> cnt(26);
    for(auto c : s)
        cnt[c - 'a']++;
    vector<int> blocks;
    int p = 25;
    //for(auto x : uwu)
    //    cout << x << " ";
    //cout << endl;
    for(int i = 0; i < uwu.size(); i++) {
        while(cnt[p] < uwu[i])
            p--;
        blocks.push_back(p);
        p--;
    }
    //for(auto x : blocks)
    //    cout << x << " ";
    //cout << endl;
    for(int i = 0; i < n; i++)
        cout << (char)('a' + blocks[-v[i] - 1]);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}