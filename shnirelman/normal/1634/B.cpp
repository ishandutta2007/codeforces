#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n, x;
    li y;
    cin >> n >> x >> y;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (a[i] % 2);
    }

    if((x + cnt) % 2 == y % 2)
        cout << "Alice\n";
    else
        cout << "Bob\n";
//
//    for(int ind = 0; ind < 2; ind++) {
//        set<li> st;
//        st.insert(x);
//        for(int i = 0; i < n; i++) {
//            set<li> nst;
//            for(li z : st) {
//                nst.insert(a[i] + z);
//                nst.insert(a[i] ^ z);
//            }
//            st = nst;
//        }
//
//        for(li z : st)
//            cout << z << ' ';
//        cout << endl;
//
//        x += 3;
//    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}