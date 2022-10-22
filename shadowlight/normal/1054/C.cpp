#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Tree {
    int n;
    vector <int> t;
    Tree(int n) : t(2 * n, 0), n(n) {}
    void add(int v, int x) {
        v += n;
        while (v) {
            t[v] += x;
            v /= 2;
        }
    }
    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                res += t[l++];
            }
            if (r % 2 == 0) {
                res += t[r--];
            }
        }
        return res;
    }
};

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
    vector <int> l(n), r(n);
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        a[i] = {l[i] + r[i], i};
    }
    sort(a.begin(), a.end());
    int last = -1;
    Tree t(n);
    vector <int> save;
    vector <int> res(n);
    int num = n + 1;
    for (int i = 0; i < n; i++) {
        int x = a[i].first;
        int pos = a[i].second;
        if (x != last) {
            last = x;
            for (int b : save) {
                t.add(b, 1);
                res[b] = num;
            }
            num--;
            save.clear();
        }
        //cout << pos << " " << l[pos] << " " << r[pos] << "\n";
        if (t.get(0, pos - 1) != l[pos] || t.get(pos + 1, n - 1) != r[pos]) {
            cout << "NO\n";
            return 0;
        }
        save.push_back(pos);
    }
    for (int x : save) {
        res[x] = num;
    }
    cout << "YES\n";
    for (int x : res) {
        cout << x << " ";
    }
}