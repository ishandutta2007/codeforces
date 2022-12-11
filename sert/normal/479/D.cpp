#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 1003;

ll a[N], n, l, x, y;
ll p;

bool check(ll d) {
    if (d > l) return false;
    for (int i = 0; i < n - 1; i++) {
            p = lower_bound(a, a + n, a[i] + d) - a;
            if (a[p] == a[i] + d) 
                return true;
        }
    return false;
}

bool checkb(ll d) {
    if (d > l) return false;
    for (int i = n - 2; i >= 0; i--) {
            p = lower_bound(a, a + n, a[i] + d) - a;
            if (a[p] == a[i] + d) 
                return true;
        }
    return false;    
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> l >> x >> y;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n++] = l * 2 + 1;

    if (check(x)) {
        if (check(y)) {
            cout << "0\n";
        } else {
            cout << "1\n" << y << "\n";
        }
    } else if (check(y)) {
        cout << "1\n" << x << "\n";
    } else {
        if (check(y - x)) {
            if (a[p] + x <= l) {
                cout << "1\n" << a[p] + x;
                return 0;
            }
            if (a[p] - y >= 0) {
                cout << "1\n" << a[p] - y;
                return 0;
            }
        }

        if (checkb(y - x)) {
            if (a[p] + x <= l) {
                cout << "1\n" << a[p] + x;
                return 0;
            }
            if (a[p] - y >= 0) {
                cout << "1\n" << a[p] - y;
                return 0;
            }
        } 

        if (check(y + x)) {
            cout << "1\n" << a[p] - x;
        } else {
            cout << "2\n" << x << " " << y << "\n";
        }
    }

    //return 0;
}