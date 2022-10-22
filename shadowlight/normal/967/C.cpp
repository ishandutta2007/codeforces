#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m, cl, ce, v;
vector <int> l, e;

int get(int y1, int y2, vector <int> &l) {
    int posl = lower_bound(l.begin(), l.end(), y1) - l.begin();
    if (posl == (int) l.size()) {
        if (posl) {
            return 2 * (y1 - l[posl - 1]);
        } else {
            return INF;
        }
    } else if (l[posl] > y2) {
        if (posl) {
            return 2 * min(y1 - l[posl - 1], l[posl] - y2);
        } else {
            return 2 * (l[posl] - y2);
        }
    } else {
        return 0;
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
    cin >> n >> m >> cl >> ce >> v;
    l.resize(cl), e.resize(ce);
    for (int i = 0; i < cl; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < ce; i++) {
        cin >> e[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        if (x2 == x1) {
            cout << y2 - y1 << "\n";
            continue;
        }
        int d = abs(x2 - x1);
        int wl = y2 - y1 + d + get(y1, y2, l);
        int we = y2 - y1 + (d - 1) / v + 1 + get(y1, y2, e);
        cout << min(wl, we) << "\n";
    }
}