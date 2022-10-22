#include <bits/stdc++.h>

#define f first
#define s second
#define endl '\n'

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

bool cmp(pii a, pii b) {
    return abs(a.f) + abs(a.s) < abs(b.f) + abs(b.s);
}

pii a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >>  a[i].s;
        ans += 2 + (a[i].f != 0) * 2 + (a[i].s != 0) * 2;
    }

    sort(a, a + n, cmp);

    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        if(a[i].f < 0) {
            cout << 1 << ' ' << -a[i].f << ' ' << 'L' << endl;
        } else if(a[i].f > 0) {
            cout << 1 << ' ' << a[i].f << ' ' << 'R' << endl;
        }

        if(a[i].s < 0) {
            cout << 1 << ' ' << -a[i].s << ' ' << 'D' << endl;
        } else if(a[i].s > 0) {
            cout << 1 << ' ' << a[i].s << ' ' << 'U' << endl;
        }

        cout << 2 << endl;

        if(a[i].s < 0) {
            cout << 1 << ' ' << -a[i].s << ' ' << 'U' << endl;
        } else if(a[i].s > 0) {
            cout << 1 << ' ' << a[i].s << ' ' << 'D' << endl;
        }

        if(a[i].f < 0) {
            cout << 1 << ' ' << -a[i].f << ' ' << 'R' << endl;
        } else if(a[i].f > 0) {
            cout << 1 << ' ' << a[i].f << ' ' << 'L' << endl;
        }

        cout << 3 << endl;
    }
}