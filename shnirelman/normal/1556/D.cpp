//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
1
2 2 4
0 1000000
0 1000000
1 0
1000000 1
999999 1000000
0 999999
*/

int And(int i, int j) {
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;

    return res;
}

int Or(int i, int j) {
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;

    return res;
}

//vector<int> A = {1,6,4,2,3,5,4};
//vector<int> A = {3, 3, 7, 1};
//
//int And(int i, int j) {
//    return A[i] & A[j];
//}
//
//int Or(int i, int j) {
//    return A[i] | A[j];
//}

void solve() {
    int n, k;
    cin >> n >> k;

    int oxy = Or(0, 1), oxz = Or(0, 2), oyz = Or(1, 2);
    int axy = And(0, 1), axz = And(0, 2), ayz = And(1, 2);



    vector<int> a(n, 0);
    for(int i = 0; i < 30; i++) {
        for(int x = 0; x < 2; x++) {
            for(int y = 0; y < 2; y++) {
                for(int z = 0; z < 2; z++) {
                    if((((oxy >> i) & 1) == (x | y)) && (((oxz >> i) & 1) == (x | z)) && (((oyz >> i) & 1) == (y | z)) &&
                       (((axy >> i) & 1) == (x & y)) && (((axz >> i) & 1) == (x & z)) && (((ayz >> i) & 1) == (y & z))) {
                        a[0] |= (x << i);
                        a[1] |= (y << i);
                        a[2] |= (z << i);
                       }
                }
            }
        }
    }

    for(int i = 3; i < n; i++) {
        int oi = Or(0, i);
        int ai = And(0, i);

//        cout << oi << ' ' << ai << endl;

        for(int j = 0; j < 30; j++) {
            for(int b = 0; b < 2; b++) {
//                cout << i << ' ' << j << ' ' << ((oi >> j) & 1) << ' ' << ((ai >> j) & 1) << ' ' <<
//                    (a[0] >> j) << ' ' << b << endl;
                if(((oi >> j) & 1) == ((a[0] >> j) & 1 | b) && ((ai >> j) & 1) == ((a[0] >> j) & b)) {
                    a[i] |= (b << j);
//                    cout << i << ' ' << j << ' ' << ((oi >> j) & 1) << ' ' << ((ai >> j) & 1) << ' ' <<
//                    (a[0] >> j) << ' ' << b << endl;
//                    cout << i << ' ' << j << ' ' << b << ' ' << endl;
                }

            }

        }
    }

//    for(auto x : a)
//        cout << x << ' ';
//    cout << endl;

    sort(a.begin(), a.end());

    cout << "finish " << a[k - 1] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}