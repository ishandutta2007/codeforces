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

const int INF = 1000000000;
int d[107][107];

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int n;
    cin >> n;
    vector<pair<int,int> > a;
    vector<pair<int,int> > b;
    

    FOR(i,0,107)
        FOR(j,0,107)
            d[i][j] = INF;

    FOR(i,0,107)
        d[i][i] = 0;

    FOR(i,0,n){
        int t,l,r;
        cin >> t >> l >> r;
        if (t == 1){
            a.PB(MP(l,r));
            FOR(i,0,a.size() - 1){
                if ((a[i].first > l && a[i].first < r) || (a[i].second > l && a[i].second < r))
                    d[i][a.size() - 1] = 1;
                if ((a[i].first < l && a[i].second > l) || (a[i].first < r && a[i].second > r))
                    d[a.size() - 1][i] = 1;
            }
            FOR(k,0,a.size())
            FOR(i,0,a.size())
                FOR(j,0,a.size())
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);


        }
        else{
            if (d[l - 1][r - 1] < INF){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }



    return 0;
}