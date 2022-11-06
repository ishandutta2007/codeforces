#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        x--;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            cnt[u]++;
            cnt[v]++;
        }
        if (cnt[x] <= 1) cout << "Ayush\n"; else cout << ((n & 1) ? "Ashish\n" : "Ayush\n");
    }
    return 0;
}