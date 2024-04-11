#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1), perm;
    for(int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if(!cnt[x])
            perm.push_back(x);
        cnt[x]++;
    }
    for(auto x : perm)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}