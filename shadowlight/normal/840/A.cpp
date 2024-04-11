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
    int m;
    cin >> m;
    vector <pair <int, int> > a(m), b(m);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[i] = {x, i};
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    vector <int> c(m);
    for (int i = 0; i < m; i++) {
        int pos = b[i].second;
        c[pos] = a[i].first;
    }
    for (int i : c) {
        cout << i << " ";
    }

}