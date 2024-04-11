#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1007;
const double EPS = 1e-8;
const int LOGN = 30;

vector <bool> used(3, 0);
vector <bool> can(MAXN, 0);
vector <vector <int> > a;

int n;

void force(int now = 0) {
    can[now] = 1;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        for (int j = 0; j < 6; j++) {
            force(now * 10 + a[i][j]);
        }
        used[i] = false;
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n;
    a.resize(n, vector <int> (6, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> a[i][j];
        }
    }
    force();
    int x = 0;
    for (; x < MAXN; x++) {
        if (!can[x + 1]) break;
    }
    cout << x;
}