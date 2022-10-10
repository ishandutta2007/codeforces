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
        int w, l;
        cin >> w >> l;

        vector<int> ret{1, 2};
        for (int x=1; x*x<=2*l+2*w-4; x++)
            if ((2 * l + 2 * w - 4) % x == 0)
                for (int y : {x, (2 * l + 2 * w - 4) / x})
                    if ((l % y == 0 && (w - 2) % y == 0) || (w % y == 0 && (l - 2) % y == 0) || ((l - 1) % y == 0 && (w - 1) % y == 0))
                        ret.push_back(y);

        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        cout << ret.size();
        for (int x : ret)
            cout << " " << x;
        cout << "\n";
    }

    return 0;
}