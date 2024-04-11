#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, len;
int a[N], b[N];

bool check(int p) {
    if (p >= n || p <= 0)
        return true;
    if (p % 2 == 1 && a[p] <= a[p - 1]) return false;
    if (p % 2 == 0 && a[p] >= a[p - 1]) return false;
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 1 && a[i] <= a[i - 1]) {
            b[len++] = i;
            b[len++] = i - 1;
        }
        if (i % 2 == 0 && a[i] >= a[i - 1]) {
            b[len++] = i;
            b[len++] = i - 1;
        }
    }

    sort(b, b + len);
    len = unique(b, b + len) - b;
    
    if (len > 6) {
        cout << 0;
        return 0;
    }

    set<pair<int, int> > s;
    s.clear();
    bool ok;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < n; j++) {
            swap(a[b[i]], a[j]);
            ok = true;
            for (int ii = 0; ii < len; ii++) {
                ok &= check(b[ii]);
                ok &= check(b[ii] + 1);
            }
            ok &= check(j);
            ok &= check(j + 1);
            swap(a[b[i]], a[j]);
            if (ok) {
                s.insert(make_pair(min(b[i], j), max(b[i], j)));
                //cerr << min(b[i], j) << " " << max(b[i], j)
            }
        }
    cout << s.size();

    return 0;
}