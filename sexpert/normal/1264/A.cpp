#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    vector<int> red;
    int cur = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i - 1])
            cur++;
        else {
            red.push_back(cur);
            cur = 1;
        }
    }
    red.push_back(cur);
    int g = red[0], s = 0, b = 0, p = 1;
    while(p < red.size() && s <= g) {
        s += red[p];
        p++;
    }
    while(p < red.size() && b <= g) {
        b += red[p];
        p++;
    }
    if(p == red.size() || g + s + b > n/2) {
        cout << "0 0 0\n";
        return; 
    }
    while(p < red.size() && g + s + b + red[p] <= n/2) {
        b += red[p];
        p++;
    }
    cout << g << " " << s << " " << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}