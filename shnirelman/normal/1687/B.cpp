#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

int query(string s) {
    cout << "? " << s << endl;

    int res;
    cin >> res;

    return res;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<pii> l(m);
    for(int i = 0; i < m; i++) {
        string s(m, '0');
        s[i] = '1';

        l[i] = {query(s), i};
    }

    sort(l.begin(), l.end());

    string s(m, '0');
    int lst = 0;
    for(int i = 0; i < m; i++) {
        s[l[i].s] = '1';

        int res = query(s);

        if(res - lst < l[i].f)
            s[l[i].s] = '0';
        else
            lst = res;
    }

    cout << "! " << lst << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}