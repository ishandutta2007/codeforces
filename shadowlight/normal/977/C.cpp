#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9;
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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid) {
                cnt++;
            }
        }
        if (cnt >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= r) {
            cnt++;
        }
    }
    if (cnt != k) {
        cout << -1;
    } else {
        cout << r;
    }
}