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

string s[55];

map<string , int> M;
int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int a[3][3];
    FOR(i,0,3)
        FOR(j,0,3)
            a[i][j] = 1;

    FOR(i,0,3)
        FOR(j,0,3){
            int t;
            cin >> t;
            if (t & 1){
                FOR(di,-1,2)
                    FOR(dj,-1,2)
                        if (abs(di) + abs(dj) <= 1)
                            if (i + di >= 0 && i + di < 3 && j + dj >= 0 && j + dj < 3)
                                a[i + di][j + dj] ^= 1;
            }
    }

    FOR(i,0,3){
        FOR(j,0,3)
            cout << a[i][j] ;
        cout << endl;
    }

    return 0;
}