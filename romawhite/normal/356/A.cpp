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
const int MAX = 128;

int nx[300007];
int res[300007];

int main()
{

    //freopen("in.txt", "r", stdin);

    int n,m;
    cin >> n >> m;
    FOR(i,0,n)
        nx[i] = i + 1;

    FOR(i,0,m){
        int l,r,x;
        scanf("%d%d%d" , &l , &r, &x);
        --l;--r;--x;
        for(;l <= r;){
            int L = nx[l];

            if (l < x)
                nx[l] = x;
            if (l > x) nx[l] = nx[r];

            if (res[l] == 0 && l != x)
                res[l] = x + 1;
            l = L;
        }
    }

    FOR(i,0,n)
        cout << res[i] << ' ';

    return 0;

}