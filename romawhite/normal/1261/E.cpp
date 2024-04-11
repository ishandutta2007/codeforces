#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);

int R[MAX][MAX];
int a[MAX];

int H[MAX];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        cin >> a[i];
    }

    FOR(i,0,n + 1)
    {
        H[i] = 0;
    }

    FILL(R, 0);

    FOR(i,0,n)
    {
        vector<PII> h;
        FOR(j,0,n + 1)
        {
            h.push_back(MP(H[j], j));
        }
        sort(ALL(h));
        int r1 = 0, r2 = 1;
        FOR(j,0,n)
        {
            if (h[j].first == h[j + 1].first)
            {
                r1 = h[j].second;
                r2 = h[j + 1].second;
            }
        }
        R[r2][i] = 1;
        -- a[i];

        vector<pair<int, int> > C;
        C.push_back(MP(H[r1] * 2, r1));
        C.push_back(MP(H[r2] * 2 + 1, r2));

        FOR(j,0,n + 1)
        {
            if (j == r1 || j == r2)
                continue;
            if (a[i] > 0)
            {
                R[j][i] = 1;
                -- a[i];
            }
            C.push_back(MP(H[j] * 2 + R[j][i], j));
        }
        sort(ALL(C));
        H[C[0].second] = 0;
        FOR(i,1,n + 1)
        {
            H[C[i].second] = H[C[i - 1].second];
            if (C[i].first != C[i - 1].first)
                H[C[i].second] ++;
        }
    }

    cout << n + 1 << endl;
    FOR(i,0,n + 1)
    {
        FOR(j,0,n)
        {
            cout << R[i][j];
        }
        cout << endl;
    }

    


}