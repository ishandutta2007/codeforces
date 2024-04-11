#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:32777216")
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
#include <complex>
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
const int MAX = 2007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;


int main()
{
    //freopen("in.txt" , "r", stdin);
    
    vector<pair<double,double> > a;
    a.push_back(MP(0,0));
    
    pair<double,double> p = MP(1,0);
    
    FOR(i,0,6)
    {
        int x;
        cin >> x;
        pair<double, double> nw = a.back();
        nw.first += x * p.first;
        nw.second += x * p.second;
        a.push_back(nw);
        pair<double, double> pp;
        pp.first = p.first * cos(Pi / 3) - p.second * sin(Pi / 3);
        pp.second = p.first * sin(Pi / 3) + p.second * cos(Pi / 3);
        p = pp;
    }
    //FOR(i,0,a.size())
    //{
    //    cout << a[i].first << ' ' << a[i].second << endl;
    //}
    
    double S = 0;
    FOR(i,0,6)
    {
        S += a[i + 1].first * a[i].second - a[i].first * a[i + 1].second;
    }
    
    S = abs(S);
    int res = S / (0.5 * sqrt(3)) + 0.5;
    
    cout << res << endl;
    
    return 0;
}