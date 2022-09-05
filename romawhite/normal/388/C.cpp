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

int a[107];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    int r1 = 0;
    int r2 = 0;
    vector<int> rest;
    FOR(i,0,n){
        int l;
        cin >> l;
        FOR(j,0,l){
            scanf("%d" , &a[j]);
        }

        if (l % 2 == 1){
            rest.push_back(a[l / 2]);
        }

        FOR(j,0,l / 2)
            r1 += a[j];

        FOR(j,l / 2 + l % 2 , l)
            r2 += a[j];

    }

    sort(ALL(rest));
    reverse(ALL(rest));

    FOR(i,0,rest.size())
        if (i % 2 == 0)
            r1 += rest[i];
        else r2 += rest[i];

    cout << r1 << ' ' << r2 << endl;

}