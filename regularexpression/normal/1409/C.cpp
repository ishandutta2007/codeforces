#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int d = y-x;
        vector<int> ans;
        for (int q=1; q<=d; ++q) {
            if (d%q == 0) {
                // s+q*(n-1)>=y
                // s>=y-q*(n-1)
                int s = max(1, y-q*(n-1));
                while (s%q != y%q) ++s;
                if (s>x) continue;
                vector<int> v;
                for (int i=0; i<n; ++i) v.push_back(s+q*i);
                if (ans.empty() || v.back()<ans.back()) ans = v;
            }
        }
        for (auto x:ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}