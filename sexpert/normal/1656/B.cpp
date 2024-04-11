#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        set<int> lol;
        for(auto &x : v) {
            cin >> x;
            lol.insert(x);
        }
        bool good = false;
        for(auto &x : v)
            if(lol.count(x + k))
                good = true;
        cout << (good ? "YES" : "NO") << '\n';
    }
}