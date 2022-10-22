#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;
const double EPS = 1e-8;

ll res = 0;

void calc(vector <map <int, int> > &mas, bool even) {
    int pr = INF;
    for (int i = -MAXN; i < MAXN; i++) {
        if (!mas[0].count(i)) {
            mas[0][i] = pr;
        } else {
            pr = min(pr, mas[0][i]);
            mas[0][i] = pr;
        }
    }
    pr = -INF;
    for (int i = -MAXN; i < MAXN; i++) {
        if (!mas[2].count(i)) {
            mas[2][i] = pr;
        } else {
            pr = max(pr, mas[2][i]);
            mas[2][i] = pr;
        }
    }
    pr = INF;
    for (int i = MAXN; i >= -MAXN; i--) {
        if (!mas[1].count(i)) {
            mas[1][i] = pr;
        } else {
            pr = min(pr, mas[1][i]);
            mas[1][i] = pr;
        }
    }
    pr = -INF;
    for (int i = MAXN; i >= -MAXN; i--) {
        if (!mas[3].count(i)) {
            mas[3][i] = pr;
        } else {
            pr = max(pr, mas[3][i]);
            mas[3][i] = pr;
        }
    }
    //cout << "KEKOS\n";
    int st = -MAXN;
    if (even) {
        st++;
    }
    for (int i = st; i <= MAXN; i += 2) {
        int down = max(mas[0][i], mas[1][i]);
        int up = min(mas[2][i], mas[3][i]);
        //cout << i << " " << up << " " << down << "\n";
        if (up >= down) {
            res += (up - down) / 2 + 1;
        }
    }
}

void upd(map <int, int> &a, int x, int y, bool min_fl) {
    if (!a.count(x)) {
        a[x] = y;
    } else if (min_fl) {
        a[x] = min(a[x], y);
    } else {
        a[x] = max(a[x], y);
    }
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
    int n;
    cin >> n;
    vector <map <int, int> > odd(4), even(4);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int x1 = x + y, y1 = x - y;
        x = x1, y = y1;
        //cout << x << " " << y << "\n";
        if (x % 2) {
            upd(even[0], x + 1, y + 1, true);
            upd(even[1], x - 1, y + 1, true);
            upd(even[2], x + 1, y - 1, false);
            upd(even[3], x - 1, y - 1, false);
        } else {
            upd(odd[0], x + 1, y + 1, true);
            upd(odd[1], x - 1, y + 1, true);
            upd(odd[2], x + 1, y - 1, false);
            upd(odd[3], x - 1, y - 1, false);
        }
    }
    calc(even, true);
    calc(odd, false);
    cout << res;
}