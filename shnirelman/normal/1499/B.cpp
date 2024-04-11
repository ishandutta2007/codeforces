#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int a = -1;
    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(fl) {
                break;
            } else {
                fl = true;
            }
        } else
            fl = false;
        a = i;
    }

    int b = n;
    fl = false;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') {
            if(fl) {
                break;
            } else {
                fl = true;
            }
        } else
            fl = false;
        b = i;
    }

//    cout << n << ' ' <<
    cout << (a + 1 >= b ? "Yes" : "No") << endl;

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}