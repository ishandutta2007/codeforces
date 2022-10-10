#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i > 0)
            v[i] ^= v[i - 1];
    }
    cout << endl;
    if(v[n - 1] == 0) {
        cout << -1 << endl;
        return 0;
    }
    set<int> used;
    for(int b = 30; b >= 0; b--) {
        int r = 0, cur;
        for(int i = 0; i < n; i++) {
            if(!used.count(i) && (v[i] & (1 << b))) {
                used.insert(i);
                r = v[i];
                cur = i;
                break;
            }
        }
        if(r == 0)
            continue;
        for(int i = 0; i < n; i++) {
            if(i == cur)
                continue;
            if(v[i] & (1 << b))
                v[i] ^= r;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] != 0)
            ans++;
    }
    cout << ans << endl;
}