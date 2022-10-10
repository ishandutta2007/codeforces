#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    set<int, greater<int>> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> v;
    for(auto x : s)
        v.push_back(x);
    sort(v.rbegin(), v.rend());
    int ans = v[0];
    int bnd = v.size() - 1;
    for(int i = 0; i < bnd; i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] % v[j] == 0) continue;
            ans = max(ans, v[i] + v[j]);
            bnd = min(bnd, j);
            break;
        }
    }
    bnd = v.size() - 1;
    for(int i = 0; i <= bnd; i++) {
        int ob = v.size() - 1;
        for(int j = i + 1; j <= ob; j++) {
            if(v[i] % v[j] == 0) continue;
            for(int k = j + 1; k < v.size(); k++) {
                if(v[i] % v[k] == 0 || v[j] % v[k] == 0) continue;
                ans = max(ans, v[i] + v[j] + v[k]);
                ob = min(ob, k);
                bnd = min(bnd, k);
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}