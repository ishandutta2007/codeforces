#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int sumd(int x) {
    int cnt = 1;
    while (x) {
        if (x % 10) {
            cnt *= x % 10;
        }
        x /= 10;
    }
    return cnt;
}

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
    vector <vector <int> > a(MAXN, vector <int> (10, 0));
    vector <int> d(MAXN, 0);
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = a[i - 1][j];
        }
        if (i < 10) {
            d[i] = i;
        } else {
            d[i] = d[sumd(i)];
        }
        a[i][d[i]]++;
    }
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << a[r][k] - a[l - 1][k] << "\n";
    }
}