#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int A = 26;

int a[N];

bool is(int n, int x) {
    for(int i = 0, j = n - 1; i < j; i++, j--) {
        if(a[i] != a[j]) {
            if(a[i] == x) {
                i++;
            } else if(a[j] == x) {
                j--;
            } else
                return false;

            i--;
            j++;
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = -1, y = -1;
    for(int i = 0; i * 2 < n; i++) {
        if(a[i] != a[n - i - 1]) {
            x = a[i];
            y = a[n - i - 1];
            break;
        }
    }

    if(x == -1) {
        cout << "YES" << endl;
        return;
    }

    cout << (is(n, x) || is(n, y) ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}