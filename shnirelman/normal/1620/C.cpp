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
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
3
2 4 3
a*
4 1 3
a**a
6 3 20
**a***

1
2 4 3
a*

1
6 3 20
**a***
*/

void solve() {
    int n, k;
    li x;
    cin >> n >> k >> x;

    string s;
    cin >> s;

    vector<int> a;

    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            cur++;
        }

        if(s[i] == 'a' || i == n - 1) {
            if(cur != 0) {
                a.push_back(cur);
                cur = 0;
            }
        }
    }

//    for(int i = 0; i < a.size(); i++) {
//        cout << a[i] << ' ';    }
//    cout << endl;
//    return ;

    vector<li> suf(a.size() + 1, 1ll);
    for(int i = int(a.size()) - 1; i >= 0; i--) {
        if(ld(suf[i + 1]) * (a[i] * k + 1) > INF64)
            suf[i] = INF64;
        else
            suf[i] = suf[i + 1] * (a[i] * k + 1);
    }

//    for(int i = 0; i < suf.size(); i++)
//        cout << suf[i] << ' ';
//    cout << endl;
//return;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i] * (k + 1); j++) {
            if(suf[i + 1] * (j + 1) >= x) {
                a[i] = j;
//                cout << i << ' ' << j << ' ' << suf[i + 1] << ' ' << x << endl;
                x -= suf[i + 1] * j;

                break;
//                cout << "write j " << endl;
            }
        }
    }

    cur = 0;
    for(int i = 0; i < n; ) {
        if(s[i] == 'a')
            cout << s[i++];
        else {
            for(int j = 0; j < a[cur]; j++)
                cout << 'b';
            cur++;
            while(i < n && s[i] == '*')
                i++;
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}