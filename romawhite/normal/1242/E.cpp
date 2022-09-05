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
const int MAX = 300007;
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);

VI res[MAX];

int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;

    vector<PII> A;

    FOR(i,0,n)
    {
        int x;
        cin >> x;
        A.push_back(MP(x, i));
    }
    
    sort(ALL(A));
    reverse(ALL(A));

    int s = 0;
    FOR(i,1,SZ(A))
    {
        s += A[i].first;
    }

    int cnt = A[0].first;
    VI C;
    FOR(i,0,cnt)
    {
        C.push_back(i);
    }
    res[A[0].second] = C;

    FOR(i, 1, n)
    {
        int c = 1;
        int nx = (i + 1 < n ? A[i + 1].first : 0);
        while (c < A[i].first - 1 && c < SZ(C) - 2 && SZ(C) + A[i].first - 2 * (c + 1) >= nx)
        {
            ++ c;
        }
        int id = A[i].second;
        int nv = A[i].first - 1 - c;
        FOR(j,0,c)
        {
            res[id].push_back(C.back());
            if (j + 1 < c)
                C.pop_back();
        }
        FOR(j,0,nv)
        {
            res[id].push_back(cnt);
            C.push_back(cnt);
            ++ cnt;
        }
        res[id].push_back(C[0]);
        if (SZ(C) <= 4)
        {
            C.push_back(C[0]);
            C.erase(C.begin());
        }
    }

    cout << cnt << endl;
    FOR(i,0,n)
    {
        FOR(j,0,SZ(res[i]))
        {
            cout << res[i][j] + 1 << ' ';
        }
        cout << endl;
    }

    cerr << SZ(C) << endl;

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}