#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n;
    cin >> n;
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int f = -1, s = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].first > f) {
            f = a[i].second;
        } else if (a[i].first > s) {
            s = a[i].second;
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}