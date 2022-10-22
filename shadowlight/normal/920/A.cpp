#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector <int> a(k);
        for (int j = 0; j < k; j++) {
            cin >> a[j];
        }
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[0] - mid + 1 > 1) {
                l = mid;
                continue;
            }
            if (a.back() + mid - 1 < n) {
                l = mid;
                continue;
            }
            bool fl = false;
            for (int i = 1; i < k; i++) {
                if (a[i] - mid + 1 > a[i - 1] + mid) {
                    fl = true;
                    break;
                }
            }
            if (fl) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << r << "\n";
    }
}