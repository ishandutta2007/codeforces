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
typedef long double ld;
const int N = 34;
const ld zero = 0;

ld zn, ch, cur, ee;
int n, l[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    zn = 1;
    for (int i = 0; i < n; i++) zn *= (r[i] - l[i] + 1);

    //cerr << zn << "\n";

    for (int w = 0; w < n; w++)
    for (int s = 0; s < n; s++) {
        if (s == w) continue;
        for (int cst = l[s]; cst <= r[s]; cst++) {
            cur = 1;
            if (w < s)
                cur *= min(r[w] - l[w] + 1, max(0, r[w] - cst + 1));
            else
                cur *= min(r[w] - l[w] + 1, max(0, r[w] - cst));
            for (int i = 0; i < n; i++) {
                if (i == s || i == w) continue;
                if (i > s)
                    cur *= min(r[i] - l[i] + 1, max(0, cst - l[i] + 1));
                else
                    cur *= min(r[i] - l[i] + 1, max(0, cst - l[i]));
            }

            //cerr << cst << " " << w << " " << s << " " << cur << "\n";

            ee = cst;
            ch += ee * cur;
        }
    }

    cout.precision(12);
    cout << fixed << ch / zn;


    return 0;
}