#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

/*

*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> p(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (s[i] - '0');
    }

    int c1 = p[n], c0 = n - p[n];

    if(c0 % 2 != 0 || c1 % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

//    cout << c0 << ' ' << c1 << endl;

    string a = "", b = "";
    int bala = 0, balb = 0;

    bool cur = false;
    int cur1 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(cur1 * 2 < c1) {
                a += '(';
                b += '(';
                cur1++;
            } else {
                a += ')';
                b += ')';
            }
        } else {
            if(cur) {
                a += '(';
                b += ')';
            } else {
                a += ')';
                b += '(';
            }
            cur = !cur;
        }



        bala += (a[i] == '(' ? 1 : -1);
        balb += (b[i] == '(' ? 1 : -1);

//        cout << a << ' ' << bala << endl << b << ' ' << balb << endl;

        if(bala < 0 || balb < 0) {
            cout << "NO" << endl;
            return;
        }
    }

//    cout << a << endl << b << endl;

    if(bala == 0 && balb == 0) {
        cout << "YES" << endl << a << endl << b << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}