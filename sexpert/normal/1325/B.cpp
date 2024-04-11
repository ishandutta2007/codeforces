#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << v.size() << '\n';
    }
}