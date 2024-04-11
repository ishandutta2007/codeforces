#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        cout << 1 + distance(v.begin(), min_element(v.begin(), v.end())) << " " << 1 + distance(v.begin(), max_element(v.begin(), v.end())) << '\n';
    }
}