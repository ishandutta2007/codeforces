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

int A[1007][1007];

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int n,m,d;
    cin >> n >> m >> d;
    vector<int> a;
    FOR(i,0,n*m){
        int A;
        cin >> A;
        a.PB(A);
    }

    FOR(i,1,a.size())
        if (a[i] % d != a[0] % d){
            cout << "-1\n";
            return 0;
        }

    int res = INF;

    FOR(i,0,a.size()){
        int t = 0;
        FOR(j,0,a.size())
            t += abs(a[i] - a[j]) / d;
        res = min(res , t);
    }

    cout << res << endl;

    return 0;
}