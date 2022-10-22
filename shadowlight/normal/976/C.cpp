#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Segs {
    int l, r, id;
};

bool operator<(Segs a, Segs b) {
    if (a.l == b.l) {
        return a.r > b.r;
    }
    return a.l < b.l;
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
    vector <Segs> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    int r = -1, id = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].r > r) {
            r = a[i].r;
            id = a[i].id;
        } else if (r >= a[i].r) {
            cout << a[i].id + 1 << " " << id + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << " " << -1 << "\n";
}