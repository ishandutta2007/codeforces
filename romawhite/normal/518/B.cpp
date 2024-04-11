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
#define y1 adsfadsfadfs

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 15000000;

char s[MAX];
char t[MAX];

int a[1000];
int b[1000];

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    scanf("%s" , s);
    scanf("%s" , t);
    int n = strlen(s);
    int m = strlen(t);

    FOR(i,0,n)
    {
        a[s[i]]++;
    }
    FOR(i,0,m)
    {
        b[t[i]]++;
    }

    int r1 = 0;
    int r2 = 0;
    FOR(i,0,1000)
    {
        int c = min(a[i], b[i]);
        r1 += c;
        a[i] -= c;
        b[i] -= c;
    }

    FOR(i,'A' , 'Z' + 1)
    {
        a[i - 'A' + 'a'] += a[i];
        b[i - 'A' + 'a'] += b[i];
    }

    FOR(i,'a' , 'z' + 1)
    {
        r2 += min(a[i] , b[i]);
    }

    cout << r1 << ' ' << r2 << endl;

    return 0;
}