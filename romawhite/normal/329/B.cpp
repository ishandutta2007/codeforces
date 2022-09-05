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
typedef long double LD;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;

string s[1007];
bool used[1007][1007];
int d[1007][1007];
int n,m;
pair<int,int> q[1000007];

bool ok(int x,int y){
    return x >= 0 && x < n && y >= 0 && y< m && s[x][y] != 'T' && !used[x][y];
}

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/
    
    cin >> n >> m;

    FOR(i,0,n)
        cin >> s[i];

    int sx,sy,ex,ey;

    FOR(i,0,n)
        FOR(j,0,m){
            if (s[i][j] == 'S'){
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'E'){
                ex = i;
                ey = j;
            }
    }
    
    FOR(i,0,n)
        FOR(j,0,m)
            d[i][j] = INF;

    d[ex][ey] = 0;
    used[ex][ey] = 1;

    int l = 0;
    int r = 1;
    q[0] = MP(ex,ey);

    while (r > l){
        pair<int,int> p = q[l++];
        int x = p.first;
        int y = p.second;
        FOR(dx,-1,2)
            FOR(dy,-1,2)
                if (abs(dx) + abs(dy) == 1)
                    if (ok(x + dx , y + dy)){
                        q[r++] = MP(x + dx , y + dy);
                        used[x + dx][y + dy] = 1;
                        d[x + dx][y + dy] = min(d[x + dx][y + dy] , d[x][y] + 1);
                    }
    }

    int D = d[sx][sy];
    int res = 0;
    FOR(i,0,n)
        FOR(j,0,m)
            if (s[i][j] >= '0' && s[i][j] <= '9' && d[i][j] <= D)
                res += s[i][j] - '0';
    cout << res << endl;
    return 0;
}