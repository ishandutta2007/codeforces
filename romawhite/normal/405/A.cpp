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
#include <functional>
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
const double PI = acos(-1.0);
typedef long long Int;
typedef vector<int> VI;
const int INF = 1000000000;
const int MAX = 100005;
const int MAX2 = 2000000;

int a[107];
int b[107];

int main()
{
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        cin >> a[i];
    }
    
    sort(a , a + n);
    FOR(i,0,n)
        cout << a[i] << ' ';

}