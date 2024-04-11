#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int N = 17;
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
    int n, t;
    cin >> n >> t;
    vector <vector <double> > a(n + 1, vector <double> (n + 1, 0));
    for (int i = 0; i < t; i++) {
        a[0][0] += 1;
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k <= j; k++) {
                if (a[j][k] <= 1.0) continue;
                double d = a[j][k] - 1.0;
                a[j][k] = 1.0;
                a[j + 1][k] += d / 2;
                a[j + 1][k + 1] += d / 2;
            }
        }
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k <= j; k++) {
            //cout << a[j][k] << "\n";
            if (a[j][k] >= 1.0 - EPS) {
                cnt++;
                //cout << j << " " << k << "\n";
            }
        }
    }
    cout << cnt;
}