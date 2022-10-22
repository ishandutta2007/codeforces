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
    vector <int> x(n);
    for (int i = 0; i < n; i++) {
        if (!i) {
            x[i] = a[i];
        } else {
            x[i] = a[i] - a[i - 1];
        }
    }
//    for (int y : x) {
//        cout << y << " ";
//    }
//    cout << "\n";
    vector <int> res;
    for (int l = 1; l <= n; l++) {
        bool can = true;
        for (int i = 1; i < n; i++) {
            //cout << a[i] << " " << a[i - 1] << "\n";
            if (a[i] != a[i - 1] + x[i % l]) {
                can = false;
                break;
            }
        }
        if (can) {
            res.push_back(l);
        }
    }
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << " ";
    }
}