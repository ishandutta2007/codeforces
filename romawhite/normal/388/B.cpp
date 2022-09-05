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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

#define distance sgfsdfgs

typedef long long Int;
typedef unsigned int uint;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MAX = 2048;
const int MAX2 = 1000007;
const int MOD = 1000000007;

string s[1007];

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif*/

    int k;
    cin >> k;

    FOR(i,0,1007)
        s[i].resize(1007);

    FOR(i,0,1007)
        FOR(j,0,1007)
            s[i][j] = 'N';

    vector<int> a;
    while (k){
        a.push_back(k % 10);
        k /= 10;
    }

    reverse(ALL(a));

    int n = 2 + (a.size() - 1) * 10;

    FOR(i,0,(int)a.size() - 2){
        FOR(j,0,10)
            FOR(k,0,10)
                s[2 + i * 10 + j][2 + i * 10 + 10 + k] = s[2 + i * 10 + 10 + k][2 + i * 10 + j] = 'Y';
    }

    if (a.size() > 1){
        FOR(i,0,10){
            s[2 + a.size() * 10 - 20 + i][1] = s[1][2 + a.size() * 10 - 20 + i] = 'Y';
        }
    }
    
    FOR(i,0,a.size() - 1){
        if (a[i] > 0){
            int prev  = 0;
            FOR(j,0,i){
                s[prev][n] = s[n][prev] = 'Y';
                prev = n;
                ++n;
            }
            FOR(j,0,a[i]){
                s[prev][n] = s[n][prev] = 'Y';
                FOR(k,0,10)
                    s[n][2 + i * 10 + k] = s[2 + i * 10 + k][n] = 'Y';
                ++n;
            }
        }
    }

    int prev  = 0;
        FOR(j,0,a.size() - 1){
            s[prev][n] = s[n][prev] = 'Y';
            prev = n;
            ++n;
        }

    FOR(j,0,a.back()){
        s[prev][n] = s[n][prev] = 'Y';
        s[n][1] = s[1][n] = 'Y';
        ++n;
    }

    cout << n << endl;
    FOR(i,0,n){
        FOR(j,0,n)
            printf("%c" , s[i][j]);
        printf("\n");
    }
}