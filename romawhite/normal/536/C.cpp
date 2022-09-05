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
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 7000;
const int BASE = 1000000000;
const Int INF2 = 10000000000000007LL;
const int MOD = 1000000007;

map<pair<int,int>, vector<int> > ids;

vector<pair<int,int> > a;

bool ccw(pair<int,int> A, pair<int,int> B, pair<int,int> C)
{
    Int R1 = 1LL * (A.first - B.first) * (B.second - C.second) * A.second * C.first;
    Int R2 = 1LL * (A.second - B.second) * (B.first - C.first) * A.first * C.second;
    return R1 < R2;
}

bool Comp(pair<int,int> a , pair<int,int> b)
{
    return a.first > b.first || (a.first == b.first && a.second > b.second);
}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        int x , y;
        scanf("%d%d" , &x , &y);
        a.push_back(MP(x , y));
        ids[MP(x , y)].push_back(i);
    }

    sort(ALL(a), Comp);
    a.resize(unique(ALL(a)) - a.begin());

    /*FOR(i,0,a.size())
    {
        cout << a[i].first << ' ' << a[i].second << endl;
    }*/

    vector<pair<int, int> > b;
    b.push_back(a[0]);
    FOR(i,1,a.size())
    {
        if (a[i].second <= b.back().second) continue;
        while (b.size() >= 2 && ccw(b[b.size() - 2] , b[b.size() - 1] , a[i]))
        {
            b.pop_back();
        }
        b.push_back(a[i]);
    }

    vector<int> res;
    FOR(i,0,b.size())
    {
        vector<int> v = ids[b[i]];
        FOR(j,0,v.size())
        {
            res.push_back(v[j] + 1);
        }
    }
    sort(ALL(res));
    FOR(i,0,res.size())
    {
        printf("%d " , res[i]);
    }
    cout << endl;


    return 0;
}