#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <set<long long> > s(n);
    map <long long, int> mp;
    for(int i = 0; i < n; i ++) {
        string p;
        cin >> p;
        for(int j = 0; j < p.length(); j ++) {
            long long x = 0;
            for(int k = j; k < p.length(); k ++) {
                x = x<<4|(p[k]-'0'+1);
                s[i].insert(x);
            }
        }
        for(auto x : s[i]) mp[x] ++;
    }
    auto Len = [&](long long x) {
        int res = 0;
        while(x) res ++, x >>= 4;
        return res;
    };
    function <void(long long)> print = [&](long long x) {
        if(x == 0) return;
        print(x>>4);
        cout << (x&15)-1;
    };
    for(int i = 0; i < n; i ++) {
        int len = 20;
        long long ans;
        for(auto x : s[i]) if(mp[x] == 1) {
            int cur = Len(x);
            if(cur < len) len = cur, ans = x;
        }
        print(ans), cout << '\n';
    }
}