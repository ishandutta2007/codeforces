#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;


int main() {
    cin >> n >> k;
    if(k == 1) {
        for(int i = 0; i < n; i++) {
            if(i == 0) cout << 1;
            else cout << 0;
        }
        return 0;
    }
    if(3 * k - 2 <= n) {
        string rep, res;
        rep.push_back('1');
        for(int i = 1; i < k; i++) rep.push_back('0');
        res = rep.substr(1);
        res += rep;
        while(res.size() < n) {
            res += rep.substr(0, k - 1);
        }
        for(int i = 0; i < n; i++) cout << res[i];
        return 0;
    }
    string rep, res;
    int len = (n - k) / 2 + 1;
    rep.push_back('1');
    for(int i = 1; i < len; i++) rep.push_back('0');
    while(res.size() < n) {
        res += rep;

    }
    for(int i = 0; i < n; i++) cout << res[i];
    return 0;




}