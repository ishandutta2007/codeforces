#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<int> C, E;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (A[i - 1] != A[i]) {
            C.pb(cnt);
            E.pb(A[i - 1]);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    C.pb(cnt);
    E.pb(A[n - 1]);
    int ans = 0;
    int last = -1;
    set<int> ends;
    for (int i = 0; i < (int) C.size(); i++) {
        int x = C[i];
        if (x >= 2) {
            if (ends.find(E[i]) == ends.end()) {
                ans++;
                ends.insert(E[i]);
            } else {
                ends = {last, E[i]};
            }
        } else {
            if (ends.find(E[i]) == ends.end()) {
                ans += 1;
                ends.insert(E[i]);
            } else {
                ends = {last, E[i]};
            }
        }
        last = E[i];
    }
    cout << ans << '\n';

}