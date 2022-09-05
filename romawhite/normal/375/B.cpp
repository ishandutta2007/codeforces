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

int a[5005][5005];
int b[5005];

int main()
{
    int n,m;
    cin >> n >> m;
    string s;
    FOR(i,0,n){
        cin >> s;
        FOR(j,0,m)
            a[i][j] = s[j] -'0';
    }
    
    FOR(i,0,n)
        FOR(j,1,m){
            if (a[i][j])
                a[i][j] += a[i][j - 1];
    }


    int res = 0;

    FOR(j,0,m){
        FILL(b,0);
        FOR(i,0,n)
            b[a[i][j]]++;
        int c = n;
        FOR(l,0,m + 1){
            c -= b[l];
            if (b[l + 1] != 0){
                res = max(res , c * (l + 1));
            }
        }
    }

    cout << res << endl;

}