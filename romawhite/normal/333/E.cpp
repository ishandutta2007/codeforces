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

const int INF = 1000000000;

typedef long long Int;
typedef long double LD;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

Int g[3007][57];

int dist(int x1,int y1,int x2,int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void add(int x,int y){
    g[x][y / 60] |= (1LL << (y % 60));
    g[y][x / 60] |= (1LL << (x % 60));
}

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif*/
    //freopen("out.txt" , "w" , stdout); 

    int n;
    cin >> n;
    vector<pair<int,int> > a;

    FOR(i,0,n){
        int x,y;
        cin >> x >> y;
        a.PB(MP(x,y));
    }

    vector<pair<int,pair<int,int> > > d(n * (n - 1) / 2);
    int id = 0;

    FOR(i,0,n)
        FOR(j,i + 1,n){
            d[id++] = (MP(dist(a[i].first , a[i].second , a[j].first , a[j].second) , MP(i,j)));
    }

    sort(ALL(d));

    RFOR(i,d.size() , 0){
        int x = d[i].second.first;
        int y = d[i].second.second;
        bool ok = 1;
        FOR(t,0,55)
            if (g[x][t] & g[y][t]){
                double res = 0.5 * sqrt(1.0 * d[i].first);
                printf("%.12f\n" , res);
                return 0;
            }
        add(x,y);
    }

    return 0;
}