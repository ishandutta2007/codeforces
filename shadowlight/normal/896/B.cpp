#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> a;

bool check() {
    for (int x : a) {
        if (x == -1) {
            return false;
        }
    }
    return true;
}
int n, m, c;
int insert1(int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == -1 || a[i] > x) {
            a[i] = x;
            return i + 1;
        }
    }
}

int insert2(int x) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == -1 || a[i] < x) {
            a[i] = x;
            return i + 1;
        }
    }
}

int main() {
    #ifdef MY
       // freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n >> m >> c;
    a.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        if (p <= c / 2) {
            cout << insert1(p) << endl;
        } else {
            cout << insert2(p) << endl;
        }
        if (check()) {
            return 0;
        }
    }
}