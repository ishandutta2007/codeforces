#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)2e9 + 34;

ll sa, sb;

int n, m, a[N], b[N];
vector <pair<int, char> > ans;

void go(int l, int r) {
    if (l + 1 == r)
        return;
    int mx = l;
    int sum = 0;
    for (int i = l; i < r; i++) {
        sum += a[i];
        if (a[i] > a[mx])
            mx = i;
    }
    if (sum / a[mx] == r - l) {
        cout << "NO";
        exit(0);
    }

    if (mx == l) {
        while (a[mx + 1] == a[mx])
            mx++;
        while (mx + 1 < r) {
            ans.push_back({mx, 'R'});
            r--;
        }
        while (mx > l) {
            ans.push_back({mx, 'L'});
            mx--;
        }
    } else {
        while (mx > l) {
            ans.push_back({mx, 'L'});
            mx--;
            r--;
        }
        while (mx + 1 < r) {
            ans.push_back({mx, 'R'});
            r--;
        }
    }
}

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sb += b[i];
    }

    if (sa != sb) {
        cout << "NO";
        return 0;
    }

    int cr = n, cl = n;
    int sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        sum = 0;
        while (sum < b[i]) {
            sum += a[--cl];
        }
        if (sum != b[i]) {
            cout << "NO";
            return 0;
        }
        go(cl, cr);
        cr = cl;
    }

    cout << "YES\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second << "\n";
    }

    return 0;
}