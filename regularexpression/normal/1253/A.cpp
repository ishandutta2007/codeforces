#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

typedef long long ll;
typedef long double ld;

//#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> d(n);
        for (int i = 0; i < n; i++) d[i] = b[i] - a[i];
        bool ended = false;
        bool can = true;
        for (int i = 0; i < n; i++) {
            if (d[i] < 0) {
                can = false;
            }
            if (d[i] > 0 && ended) {
                can = false;
            }
            if (i > 0) {
                if (d[i] == 0 && d[i - 1] != 0) {
                    ended = true;
                }
                if (d[i] != 0 && d[i - 1] != 0 && d[i] != d[i - 1]) {
                    can = false;
                }
            }
        }
        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}