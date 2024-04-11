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
const int MAX = 3000007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);
 
string S[MAX];
int n, m;
 
PII Q[MAX];
 
bool ok(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
vector<VI> d;
vector<VI> D;
 
void bfs(int c, bool q=false)
{
    int L = 0;
    int R = c;
    FOR(i,0,n)
        FOR(j,0,m)
            d[i][j] = INF;
    FOR(i,0,c)
    {
        d[Q[i].first][Q[i].second] = 0;
    }
    while (L < R)
    {
        int x = Q[L].first;
        int y = Q[L].second;
        ++ L;
        FOR(dx,-1,2)
            FOR(dy, -1, 2)
            {
                int xx = x + dx;
                int yy = y + dy;
                if (ok(xx, yy) && d[xx][yy] == INF && (!q || D[xx][yy] > 0))
                {
                    d[xx][yy] = d[x][y] + 1;
                    Q[R ++] = MP(xx, yy);
                }
            }
    }
}
 
 
bool F(int x)
{
    int c = 0;
    FOR(i,0,n)
        FOR(j,0,m)
            if (D[i][j] >= x){
                Q[c ++] = MP(i, j);
            }
    bfs(c);
    FOR(i,0,n)
        FOR(j,0,m)
            if (S[i][j] == 'X' && d[i][j] >= x)
            {
                return false;
            }
    return true;
}
 
char buf[MAX];
 
int main(int argc, char* argv[])
{
    // ios::sync_with_stdio(false); cin.tie(0);
	
    
    cin >> n >> m;
    n += 2;
    m += 2;
    S[0] = "";
    S[n - 1] = "";
    FOR(i,0,m)
    {
        S[0] += '.';
        S[n - 1] += '.';
    }
    FOR(i,1,n - 1)
    {
 
        string s;
        scanf("%s", buf);
        s = buf;
        S[i] = "." + s + ".";
    }
 
    d = vector<VI>(n, VI(m));
 
    int c = 0;
    FOR(i,0,n)
        FOR(j,0,m)
            if (S[i][j] == '.')
            {
                Q[c++] = MP(i, j);
            }
 
    bfs(c);
    D = d;
 
    int L = 1;
    int R = 0;
    FOR(i,0,n)
        FOR(j,0,m)
            R = max(R, D[i][j] + 1);
    while (R - L > 1)
    {
        int M = (L + R) / 2;
        if (F(M))
            L = M;
        else
            R = M;
    }
 
    cout << L - 1 << endl;
    FOR(i,1,n - 1)  
    {
        FOR(j,1,m - 1)
            if (S[i][j] == 'X' && D[i][j] >= L)
            {
                printf("X");
            }
            else
            {
                printf(".");
            }
        printf("\n");
    }
 
}