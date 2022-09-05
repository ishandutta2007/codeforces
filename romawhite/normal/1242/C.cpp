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
const int MAX = 47;
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);

vector<Int> A[MAX];
Int S[MAX];

map<Int, int> M;

bool U[MAX];

vector<pair<int, PII> > C[1 << 15];
int dp[1 << 15];


int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;

    Int c = 0;
    FOR(i,0,n)
    {
        int l;
        cin >> l;
        FOR(j,0,l)
        {
            int x;
            cin >> x;
            A[i].push_back(x);
            S[i] += x;
            c += x;
            M[x] = i;
        }
    }

    if (c % n != 0)
    {
        cout << "No" << endl;
        return 0;
    }

    c /= n;
    
    FILL(U, 0);

    int b_mask = 0;
    FOR(j,0,n)
    {
        if (S[j] == c)
        {
            b_mask += (1 << j);
        }
    }

    FOR(i,0,n)
    {
        if (S[i] == c)
            continue;
        FOR(j,0,SZ(A[i]))
        {
            int mask = 0;
            vector<pair<int, PII> > R;
            bool ok = true;
            int v = i;
            Int val = A[i][j];
            while (true)
            {
                if (mask & (1 << v))
                {
                    break;
                }
                mask += (1 << v);
                Int new_val = c - S[v] + val;
                if (!M.count(new_val))
                {
                    ok = 0;
                    break;
                }
                int new_v = M[new_val];
                R.push_back(MP(new_v, MP(new_val, v)));
                v = new_v;
                val = new_val;
            }
            // cout << endl;
            if (v != i || val != A[i][j])
                ok = false;
            if (ok)
            {
                C[mask] = R;
            }
        }
    }
    FILL(dp, -1);
    dp[b_mask] = 0;
    FOR(mask, 0, 1 << n)
    {
        if (dp[mask] == -1)
            continue;
        int m = (1 << n) - 1 - mask;
        for(int s = m; s; s = (s - 1) & m) {
            if (SZ(C[s]) != 0)
            {
                dp[mask | s] = s;
            }
        }
    }
    if (dp[(1 << n) - 1] == -1)
    {
        cout << "No" << endl;
        return 0;
    }

    vector<PII> res(n);
    FOR(i,0,n)
    {
        if (S[i] == c)
        {
            res[i] = MP(A[i][0], i);
        }
    }

    int mask = (1 << n) - 1;
    while (true)
    {
        int s = dp[mask];
        if (s == 0) break;
        FOR(i,0,SZ(C[s]))
        {
            res[C[s][i].first] = C[s][i].second;
        }
        mask ^= s;
    }

    cout << "Yes" << endl;
    FOR(i,0,n)
    {
        cout << res[i].first << ' ' << res[i].second + 1 << endl;
    }
    
    
    

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}