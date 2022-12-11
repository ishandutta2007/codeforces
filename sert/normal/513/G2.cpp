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

ld ch, zn = 1;
int n, k, a[N], t, len, ni, nj;
ld p[100][100][211], ans, kol, k1, lf, rt;
ld pi[100][100][211], ppi;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    kol = ((n + 1) * n) / 2;
    //cerr << kol << "\n";

    for (int i = 0; i < 34; i++)
        for (int j = 0; j < 34; j++)
            if (a[i] < a[j])
                p[i][j][0] = 1;
            else
                pi[i][j][0] = 1;

    for (int iq = 0; iq < k; iq++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                for (int i1 = 0; i1 < n; i1++)
                    for (int j1 = i1; j1 < n; j1++) {
                        //cerr << i << " " << j << " " << i1 << " " << j1 << " ";
                        if (i >= i1 && i <= j1) ni = i1 + j1 - i; else ni = i;
                        if (j >= i1 && j <= j1) nj = i1 + j1 - j; else nj = j;
                        //cerr << ni << " " << nj << "\n";
                        if (ni < nj) {
                            p[ni][nj][iq + 1] += p[i][j][iq] / kol;
                            pi[ni][nj][iq + 1] += pi[i][j][iq] / kol;
                        } else {
                            pi[nj][ni][iq + 1] += p[i][j][iq] / kol;
                            p[nj][ni][iq + 1] += pi[i][j][iq] / kol;
                        }
                    }
            }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += pi[i][j][k];

    cout.precision(12);
    cout << fixed << ans;


    return 0;
}