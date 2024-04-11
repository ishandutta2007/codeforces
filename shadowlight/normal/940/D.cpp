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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string b;
    cin >> b;
    int l = -INF, r = INF;
    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            if (b[i] == '0') {
                for (int j = 0; j < 5; j++) {
                    r = min(a[i - j] - 1, r);
                }
            } else {
                for (int j = 0; j < 5; j++) {
                    l = max(a[i - j] + 1, l);
                }
            }
        }
    }
    cout << l << " " << r << "\n";
}