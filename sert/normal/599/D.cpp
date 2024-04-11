#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll h, x, n, l;
vector <pair<ll, ll> > ans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 1; true; i++) {
        h = x = i;
        x = (x * (x + 1) * (x * 2 + 1)) / 6;
        if (x > n)
            break;
        h = (h * (h + 1)) / 2;
        if ((n - x) % h == 0) {
            l = i + (n - x) / h;
            ans.push_back(make_pair(l, i));
            if (i != l)
                ans.push_back(make_pair(i, l));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;
}