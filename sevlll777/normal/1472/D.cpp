#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        vector<int> e, o;
        for (auto x : A) {
            if (x % 2) {
                o.pb(x);
            } else {
                e.pb(x);
            }
        }
        int al = 0, bob = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (!e.empty() && (o.empty() || e.back() >= o.back())) {
                    al += e.back();
                    e.pop_back();
                } else {
                    o.pop_back();
                }
            } else {
                if (!o.empty() && (e.empty() || o.back() >= e.back())) {
                    bob += o.back();
                    o.pop_back();
                } else {
                    e.pop_back();
                }
            }
        }
        if (al > bob) {
            cout << "Alice\n";
        } else if (bob > al) {
            cout << "Bob\n";
        } else {
            cout << "Tie\n";
        }
    }

}