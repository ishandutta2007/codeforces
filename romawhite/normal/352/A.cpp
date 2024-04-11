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


typedef long long Int;
typedef vector<int> VI;

const double PI = acos(-1.0);
const int INF = 1000000000;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    int k1 = 0 , k2 = 0;

    FOR(i,0,n){
        int x;
        cin >> x;
        if (x) ++ k1;
        else ++ k2;
    }

    if (!k2){
        cout << -1 << endl;
        return 0;
    }

    k1 = 9 * (k1 / 9);

    FOR(i,0,k1)
        cout << 5;
    if (k1)
        FOR(i,0,k2)
            cout << 0;
    else cout << 0;
    cout << endl;
    return 0;
}