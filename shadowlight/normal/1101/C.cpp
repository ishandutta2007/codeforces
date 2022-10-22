#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

struct Seg {
    int l, r, id;
};

bool operator<(Seg a, Seg b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    if (a.r != b.r) {
        return a.r < b.r;
    }
    return a.id < b.id;
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
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        vector <Seg> a;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            a.push_back({l, r, i});
        }
        sort(a.begin(), a.end());
        int last = a[0].l;
        vector <int> num(n, 0);
        for (int i = 0; i < n; i++) {
            if (a[i].l > last) break;
            last = max(last, a[i].r);
            num[a[i].id] = 1;
        }
        if (last >= a.back().l) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << num[i] + 1 << " ";
        }
        cout << "\n";
    }
}