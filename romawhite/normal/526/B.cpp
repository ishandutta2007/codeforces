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
const int MAX = 1000007;
const int MAX2 = 2000;
const int BASE = 1000000000;

int a[1 << 15];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("huffman.in" , "r" , stdin);

    int n;
    cin >> n;
    int N = (1 << (n + 1)) - 1;
    FOR(i,1,N)
        scanf("%d" , &a[i]);
    Int res = 0;
    RFOR(i,N,0)
    {
        if (2 * i + 1 >= N) continue;
        res += max(a[2 * i + 1] , a[2 * i + 2]) - min(a[2 * i + 1] , a[2 * i + 2]);
        a[i] += max(a[2 * i + 1] , a[2 * i + 2]);
    }
    cout << res << endl;

    return 0;
}