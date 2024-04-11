#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1<<30;
const int MAX = 1<<17;
const int MOD = 1000000007;

int d[505][505];
bool used[505][505];
string s[505];
int n,m;

bool ok(int x,int y){
    return x >= 0 && x < n && y >= 0 &&y < m && s[x][y] == '.' && !used[x][y]; 
}

void dfs(int x,int y){
    used[x][y] = 1;
    FOR(dx,-1,2)
        FOR(dy,-1,2)
            if (abs(dx) + abs(dy) == 1)
                if (ok(x + dx,y + dy)){
                    d[x + dx][y + dy] = d[x][y] + 1;
                    dfs(x + dx,y + dy);
                }


}

vector<pair<int,int> > a[505 * 505];

int main()
{
   /* #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    cin >> n >> m;
    FOR(i,0,n)
        cin >> s[i];

    vector<pair<char,pair<int,int> > > res; 

    FOR(i,0,n)
        FOR(j,0,m)
            if (s[i][j] == '.')
                res.PB(MP('B' , MP(i + 1 , j + 1)));

    FOR(i,0,n)
        FOR(j,0,m)
        if (ok(i,j)){
            d[i][j] = 0;
            dfs(i,j);
        }

    FOR(i,0,n)
        FOR(j,0,m)
            if (s[i][j] == '.')
                a[d[i][j]].PB(MP(i + 1,j + 1));

    RFOR(i,505 * 505 , 1)
        FOR(j,0,a[i].size()){
            res.PB(MP('D' , a[i][j]));
            res.PB(MP('R' , a[i][j]));
    }

    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i].first << ' ' << res[i].second.first << ' ' << res[i].second.second << "\n";

    return 0;
}