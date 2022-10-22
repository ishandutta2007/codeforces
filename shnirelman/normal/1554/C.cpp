//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;

    int x = 0;
    int cur = 0;
    for(int i = 30; i >= 0; i--) {
        int dn = (n >> i) & 1;
        int dm = (m >> i) & 1;
//        cout << i << ' ' << dn << ' ' << dm << ' ' << x << ' ' << cur << endl;

        if(dn == 0 && (1 << i) - 1 + cur <= m) {
//            cout << "add " << (1 << i) - 1 + cur << ' ' <<m << endl;
            x |= (1 << i);
        }

//        cout << (n ^ x) << ' ' << m  << ' '  << (n ^ x & (1 << i))<< endl;

        cur += (n ^ x) & (1 << i);

        if((n ^ x) > m) {
//            cout << "gasgg" << endl;
            break;
        }

    }

//    if((n ^ x) == m) {
//        for()
//    }

    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();



//    for(int i = 0; i <= m; i++)
//        cout << (n ^ i) << ' ';
//    cout << endl;
}