#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef int ll;

int n, m, s, f;
int t, l, r, L, R;

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> n >> m >> s >> f;
    cin >> t >> l >> r;
    m--;
    for (int i = 1; true; i++) {
        if (t < i) {
            if (m) {
                cin >> t >> l >> r;
                m--;
            } else {
                l = r = -34;
                t = 2000000000;
            }
        }

        if (f > s)
            if (s > r || s + 1 < l || i != t) {
                cout << "R";
                s++;
            } else {
                cout << "X";
            }

        if (f < s)
            if (s < l || s - 1 > r || i != t) {
                cout << "L";
                s--;
            } else {
                cout << "X";
            }
        if (f == s)
            return 0;
    }

    return 0;
}