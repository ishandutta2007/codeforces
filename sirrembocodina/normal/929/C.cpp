#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[1010];
int b[1010];
int c[1010];
int d[1010][1010];
int cnt[200100];
int sum[200100];

int main() {
    int na, nb, nc;
    cin >> na >> nb >> nc;
    forn (i, na) {
        cin >> a[i];
    }
    forn (i, nb) {
        cin >> b[i];
    }
    forn (i, nc) {
        cin >> c[i];
        cnt[c[i]]++;
    }
    sort(a, a + na);
    sort(b, b + nb);
    sort(c, c + nc);
    forn (i, nc) {
        forn (j, i - 1) {
            if (c[j] * 2 >= c[i]) {
                d[j][i + 1] += i - j - 1;
            }
        }
    }
    for (int l = nc - 2; l >= 0; --l) {
        ll cur = 0;
        for (int r = l + 1; r <= nc; ++r) {
            ll CUR = d[l][r];
            d[l][r] += d[l + 1][r];
            d[l][r] += cur;
            cur += CUR;
        }
    }
    forn (i, 200100 - 1) {
        sum[i + 1] = sum[i] + cnt[i];
    }
    ll ans = 0;
    forn (i, na) {
        int L1 = lower_bound(b, b + nb, (a[i] + 1) / 2) - b;
        int R1 = upper_bound(b, b + nb, a[i] * 2) - b;
        for (int j = L1; j < R1; ++j) {
            for (int k = L1; k < j; ++k) {
                if (b[k] * 2 < b[j]) {
                    continue;
                }
                int L = sum[(max(a[i], b[j]) + 1) / 2];
                int R = sum[min(a[i], b[k]) * 2 + 1];
                ans += d[L][R];
            }
        }
    }
    cout << ans << endl;
    return 0;
}