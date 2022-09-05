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
const int MAX = 1<<17;
const int MOD = 1000000007;

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    Int n;
    cin >> n;

    vector<Int> res;

    FOR(k,0,62){
        Int t = 1LL << k;
        Int L = 0;
        Int R = 3000000000LL;
        while (R - L > 1){
            Int X = (L + R) / 2;
            double dd = 1.0 * (X + 2 * t - 3) * X;
            if (dd > 3e18){
                R = X;
            }
            else{
                Int d = (X + 2 * t - 3) * X;
                if (d >= 2 * n)
                    R = X;
                else L = X;
            }
        }
        if ((R + 2 * t - 3) * R == 2 * n && R % 2 == 1)
            res.PB(t * R);
    }
    sort(ALL(res));
    if (res.size() == 0){
        cout << "-1\n";
        return 0;
    }

    FOR(i,0,res.size())
        cout << res[i] << endl;
    return 0;
}