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

bool used[70005];
int dp[70005];

vector<int> g[70005];
int c[70005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n , s;
    cin >> n >> s;
    vector<pair<int,int> > a;

    FOR(i,0,n){
        int x;
        cin >> x;
        a.PB(MP(x,i));
        c[i] = x;
    }

    sort(ALL(a));

    if (s < a.back().first){
        cout << -1 << endl;
        return 0;
    }

    s -= a.back().first;
    used[a.back().second] = 1;

    dp[0] = 1;

    int s1 = 0;
    FOR(i,0,a.size() - 1){
        s1 += a[i].first;
        s1 = min(s1 , s);
        RFOR(j,s1 - a[i].first + 1, 0)
            if (dp[j] && !dp[j + a[i].first])
                dp[j + a[i].first] = i + 1;
        if (dp[s])
            break;
    }

    if (!dp[s]){
        cout << -1 << endl;
        return 0;
    }

    while (s > 0){
        used[a[dp[s] - 1].second] = 1;
        s -= a[dp[s] - 1].first;
    }

    int p = a.back().second;

    RFOR(i,a.size(),0)
        if (!used[a[i].second]){
            c[p] -= a[i].first;
            g[p].PB(a[i].second);
            p = a[i].second;
        }

    FOR(i,0,n){
        cout << c[i] << ' ' << g[i].size() << ' ';
        FOR(j,0,g[i].size())
            cout << g[i][j] + 1 << ' ';
        cout << endl;
    }

    return 0;

}