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

const int INF = 1000000000;

typedef long long Int;
typedef long double LD;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif*/
    //freopen("out.txt" , "w" , stdout); 
    
    set<pair<int,int> > s;
    map<pair<int,int> , int> M;
    set<int> X;
    set<int> Y;

    FOR(i,0,8){
        int x,y;
        cin >> x >> y;
        s.insert(MP(x,y));
        M[MP(x,y)] = 1;
        X.insert(x);
        Y.insert(y);
    }

    if (s.size() < 8 || X.size() != 3 || Y.size() != 3){
        cout << "ugly\n";
        return 0;
    }
    int sx = *(++X.begin());
    int sy = *(++Y.begin());

    if (M[MP(sx,sy)]){
        cout << "ugly\n";
    }
    else cout << "respectable\n";
    return 0;
}