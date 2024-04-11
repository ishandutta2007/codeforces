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

Int a[200007];
Int s[200007];
pair<Int , int> b[200007];
int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/
    //freopen("out.txt" , "w" , stdout); 
    
    int n,k;
    cin >> n >> k;
    FOR(i,0,n)
        cin >> a[i];

    s[0] = a[0];
    FOR(i,1,n)
        s[i] = s[i - 1] + a[i];

    b[n - k] = MP(s[n - 1] - s[n - k - 1] , n - k);
    RFOR(i,n - k , 0){
        b[i] = b[i + 1];
        Int t = s[i + k - 1] - (i ? s[i - 1]:0);
        if (t >= b[i].first){
            b[i].first = t;
            b[i].second = i;
        }
    }

    pair<int,int> res;
    Int M = -1;

    FOR(i,0,n - k){
        Int t = s[i + k - 1] - (i ? s[i - 1]:0);
        if (t + b[i + k].first > M){
            M = t + b[i + k].first;
            res.first = i;
            res.second = b[i + k].second;
        }
    }

    cout << res.first + 1 << ' ' << res.second + 1 << endl;

    return 0;
}