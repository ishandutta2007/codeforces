#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(11);
        for (int i=0; i<n; i++) {
            int b, d;
            cin >> b >> d;
            a[d] = max(a[d], b);
        }

        if (find(a.begin() + 1, a.end(), 0) != a.end())
            cout << "MOREPROBLEMS\n";
        else
            cout << accumulate(a.begin() + 1, a.end(), 0) << "\n";
    }

    return 0;
}