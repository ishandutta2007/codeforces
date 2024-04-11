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

    int n;
    cin >> n;

    vector<pair<pair<Int,Int> , pair<Int,Int> > > a;

    FOR(i,0,n){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.PB(MP(MP(x1,y1),MP(x2,y2)));
    }

    FOR(mask , 1,1 << n){
        mask = (1 << n) - 1;
        Int s = 0;
        Int mx = INF;
        Int my = INF;
        Int Mx = -INF;
        Int My = -INF;
        FOR(i,0,n)
            if (mask & (1 << i)){
                s += (a[i].second.first - a[i].first.first) * (a[i].second.second - a[i].first.second);
                mx = min(mx , a[i].first.first);
                my = min(my , a[i].first.second);
                Mx = max( Mx , a[i].second.first);
                My = max( My , a[i].second.second);
            }
        if (Mx - mx == My - my && (Mx - mx) * (My - my) == s){
            cout << "YES\n";
            return 0;
        }
        //cout << mask << ' ' << mx << ' ' << Mx << ' ' << my << ' ' << My << ' ' << s << endl;
    }

    cout << "NO\n";
    return 0;
}