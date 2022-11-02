#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    auto f = [&](int x) {
        int ret = 0;
        while(x) ret += x % 10, x /= 10;
        return ret;
    };
    vector <int> ans;
    for(int i = max(1, n-100); i <= n + 100; i ++) if(i+f(i) == n) ans.push_back(i);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << ' ';
    cout << endl;
}