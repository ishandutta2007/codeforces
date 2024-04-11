#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N], p[N];
ll n, m, t, k, mx;
string s;
bool fnd;
int kol;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) a[i] = i;

    mx = 0;
    for (int i = 1; i <= n; i++) mx += ((i + 1) * i) / 2;

    while (true) {

        k = 0;
        for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            t = 100500;
            for (int ii = i; ii <= j; ii++)
                t = min(t, a[ii] + 1);
            k += t;
        }

        if (k == mx) {m--; kol++;}

        if (m == 0 && !fnd) {
            fnd = true;
            for (int i = 0; i < n; i++) cout << a[i] + 1 << " ";
            cerr << "\n";
            //return 0;
        }

        if (!next_permutation(a, a + n))
            break;
    }

    //cerr << kol << "\n";

    return 0;
}