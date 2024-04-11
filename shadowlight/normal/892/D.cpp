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
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    vector <int> b(n);
    for (int i = 1; i < n; i++) {
        b[a[i - 1].second] = a[i].first;
    }
    b[a[n - 1].second] = a[0].first;
    for (int x : b) {
        cout << x << " ";
    }
}