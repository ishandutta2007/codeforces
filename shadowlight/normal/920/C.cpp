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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1;
    vector <bool> exist(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        char c;
        cin >> c;
        exist[a[i]] = true;
        if (c == '1') {
            r++;
        } else {
            //cout << l << " " << r << "\n";
            for (int j = l; j <= r; j++) {
                if (!exist[j]) {
                    cout << "NO\n";
                    return 0;
                }
                exist[j] = false;
            }
            l = r + 1;
            r = l;
        }
    }
    cout << "YES\n";
}