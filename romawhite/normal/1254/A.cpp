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
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);

char getChar(int x)
{
    if (x < 10)
        return '0' + x;
    x -= 10;
    if (x < 26)
        return 'a' + x;
    x -= 26;
    return 'A' + x;
}

string S[107];
string R[107];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        int n, m, k;
        cin >> n >> m >> k;
        FOR(i,0,n)
            cin >> S[i];
        int cnt = 0;
        FOR(i,0,n)
            FOR(j,0,m)
                if (S[i][j] == 'R')
                    ++cnt;
        VI C;
        FOR(i,0,k)
        {
            C.push_back(cnt / k + (i < cnt % k));
        }
        vector<PII> path;
        FOR(i,0,n)
        {
            if (i % 2 == 0)
                FOR(j,0,m)
                    path.push_back(MP(i, j));
            else
                RFOR(j,m,0)
                    path.push_back(MP(i,j));
        }
        int id = 0;
        FOR(i,0,n)
            R[i] = S[i];
        FOR(i,0,SZ(path))
        {
            R[path[i].first][path[i].second] = getChar(id);
            if (S[path[i].first][path[i].second] == 'R')
                --C[id];
            if (C[id] == 0) ++ id;
            if (id == k) --id;
        }
        FOR(i,0,n)
            cout << R[i] << endl;
    }
    
}