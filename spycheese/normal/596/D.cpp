#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int IINF = 0x3f3f3f3f;
const int N = 2179;

int n, h;
ld p;
int x[N];
ld d[4][N][N];

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> n >> h >> p;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x, x + n);
    for (int l = n-1; l >= 0; --l)
        for (int r = l; r < n; ++r)
            for (int st = 0; st < 4; ++st)
            {
                bool hl = st & 1;
                bool hr = st & 2;
                int vl = (l == 0 ? -IINF : x[l - 1] + (hl?h:0));
                int vr = (r == n-1 ? IINF : x[r + 1] - (hr?h:0));

                int lenlfr = max(0, min(vr,x[l]+h) - max(vl,x[l]));
                int lenlfl = max(0, min(vr,x[l]) - max(vl,x[l]-h));
                int lenrfr = max(0, min(vr,x[r]+h) - max(vl,x[r]));
                int lenrfl = max(0, min(vr,x[r]) - max(vl,x[r]-h));

                if (hl && l > 0 && x[l]-x[l-1]<h)
                {
                    d[st][l][r] = (l==r?0:d[st][l+1][r]) + lenlfr;
                    continue;
                }
                if (hr && r < n - 1 && x[r+1]-x[r]<h)
                {
                    d[st][l][r] = (l==r?0:d[st][l][r-1]) + lenrfl;
                    continue;
                }
                if (l == r)
                {
                    d[st][l][r] += (1.0-p) * lenlfr;
                    d[st][l][r] += p       * lenlfl;
                    continue;
                }
                d[st][l][r] += (1-p)  * (d[st|1][l+1][r] + lenlfr);
                d[st][l][r] += p      * (d[st&2][l+1][r] + lenlfl);
                d[st][l][r] += p      * (d[st|2][l][r-1] + lenrfl);
                d[st][l][r] += (1-p)  * (d[st&1][l][r-1] + lenrfr);

                d[st][l][r] *= 0.5;

            }
    cout.precision(50);
    cout << d[0][0][n-1] << "\n";

    return 0;
}