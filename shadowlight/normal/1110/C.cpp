#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;
const int LOGN = 26;

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
    int q;
    cin >> q;
    vector <int> res(LOGN, 1);
    for (int i = 1; i < LOGN; i++) {
        int d = (1 << i) - 1;
        for (int a = d - 1; a >= 1; a--) {
            if (d % a == 0) {
                res[i] = a;
                break;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int d = 1;
        int cnt = 0;
        while (d <= a) {
            d *= 2;
            cnt++;
        }
        if (a != d - 1) {
            cout << d - 1 << "\n";
        } else {
            cout << res[cnt] << "\n";
        }
    }
}