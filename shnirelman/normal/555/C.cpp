#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
4 1
4 1 2 3 4

4 4
1 1
1 2
1 3
1 4

1 1
1 1

6 2
3 4 U
3 4 U

6 2
3 4 U
6 1 L

10 2
2 9 U
10 1 U

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n, q;
    cin >> n >> q;

    set<int> lf, up;
    lf.insert(0);
    up.insert(0);

    map<int, int> mplf, mpup;

    for(int i = 0; i < q; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;

        swap(x, y);


        if(up.count(y)) {
            cout << 0 << endl;
            continue;
        }

        if(lf.count(x)) {
            cout << 0 << endl;
            continue;
        }

        auto itlf = lf.lower_bound(x);
        auto itup = up.lower_bound(y);

        if(c == 'U') {
//            if(itlf != lf.end() && *itlf == x) {
//                cout << 0 << endl;
//                continue;
//            }

            itlf--;
            if(itup == up.end() || *itlf > n + 1 - *itup) {

                mpup[y] = *itlf;
                cout << x - *itlf << endl;
            } else {
                cout << x - mpup[*itup] << endl;
                mpup[y] = mpup[*itup];
            }

            up.insert(y);
        } else {
//            if(itup != up.end() && *itup == y) {
//                cout << 0 << endl;
//                continue;
//            }
////                cout << "gs" << endl;

            itup--;
            if(itlf == lf.end() || *itup > n + 1 - *itlf) {
//                cout << "gs" << endl;
                mplf[x] = *itup;
                cout << y - *itup << endl;
            } else {
                cout << y - mplf[*itlf] << endl;
                mplf[x] = mplf[*itlf];
            }

            lf.insert(x);
        }
    }
}