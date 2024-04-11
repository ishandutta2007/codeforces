#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, a[100010];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    int ml = min(n - 1, 10000);
    ll best = 1LL << 50;
    for (int L = 1; L <= ml; L++) {
        ll s = 0;
        int L2 = L * L;
        if (L2 > best) break;
        for (int i = 1; i <= L; i++) s += a[i];
        if (s * s + L2 < best) best = s * s + L2;
        for (int i = L + 1; i < n; i++) {
            s += a[i] - a[i-L];
            if (s <= 10000 && s >= -10000 && s * s + L2 < best) best = s * s + L2;
        }
    }
    cout << best << endl;
    return 0;
}