#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        if(*min_element(v.begin(), v.end()) == x && *max_element(v.begin(), v.end()) == x) {
            cout << "0\n";
            continue;
        }
        if(find(v.begin(), v.end(), x) != v.end()) {
            cout << "1\n";
            continue;
        }
        if(accumulate(v.begin(), v.end(), 0) == n * x) {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
}