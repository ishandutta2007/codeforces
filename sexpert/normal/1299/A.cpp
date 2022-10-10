#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[32], pos[32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++) {
        for(int b = 0; b < 30; b++) {
            if(v[i] & (1 << b)) {
                cnt[b]++;
                pos[b] = i;
            }
        }
    }
    for(int b = 29; b >= 0; b--) {
        if(cnt[b] != 1)
            continue;
        int t = pos[b];
        cout << v[t] << " ";
        for(int i = 0; i < n; i++)
            if(i != t) cout << v[i] << " ";
        cout << '\n';
        return 0;
    }
    for(auto x : v)
        cout << x << " ";
    cout << '\n';
}