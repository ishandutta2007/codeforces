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
#include <fstream>
#include <time.h>
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


typedef long long Int;
typedef vector<int> VI;

const double PI = acos(-1.0);
const int INF = 1000000000;

vector<int> g[100007];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    FOR(i,0,n){
        int x;
        cin >> x;
        g[x].PB(i);
    }

    vector<pair<int,int> > res;
    
    FOR(i,0,100007)
        if (g[i].size()){
            if (g[i].size() == 1){
                res.PB(MP(i,0));
            }
            else{
                int d = g[i][1] - g[i][0];
                bool ok = 1;
                FOR(j,0,g[i].size() - 1)
                    if (g[i][j + 1] - g[i][j] != d)
                        ok = 0;
                if (ok)
                    res.PB(MP(i,d));
            }
        }

    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i].first << ' ' << res[i].second << endl;

    return 0;
}