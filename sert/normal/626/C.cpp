#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

ll a2, a3, k6;
vector <pair<pair<ll, ll>, int > > e1, e2;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a2 >> a3;

    for (int i = 1; true; i++) {
        if (a2 == 0 && a3 == 0) {
            cout << i - 1;
            return 0;
        }
        if (i % 6 == 1) continue;
        if (i % 6 == 0) {
            if (a2 > 0) {
                a2--;
                k6++;
            } else {
                a3--;
            }
            continue;
        }
        if (i % 3 == 0 && a3 > 0) {
            a3--;
            continue;
        }
        if (i % 2 == 0 && a2 > 0) {
            a2--;
            continue;
        }
        if (i % 2 == 0 && k6 > 0 && a3 > 0) {
            a3--;
            k6--;
            continue;
        }

    }


    return 0;
}