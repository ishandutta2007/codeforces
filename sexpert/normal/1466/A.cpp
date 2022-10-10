#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        set<int> df;
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                df.insert(v[j] - v[i]);
        cout << df.size() << '\n';
    }
}