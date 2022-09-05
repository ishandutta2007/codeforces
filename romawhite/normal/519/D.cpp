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
const int MAX = 100007;
const int MAX2 = 15000000;

int val[26];

map<Int,int> M[26];
char s[100007];

int main()
{
    #ifndef ONLINE_JUDGE
 //       freopen("in.txt", "r", stdin);
    #endif

    FOR(i,0,26)
    {
        cin >> val[i];
    }

    scanf("%s" , s);
    int n = strlen(s);

    Int cur = 0;
    Int res = 0;
    FOR(i,0,n)
    {
        int c = s[i] - 'a';
        cur += val[c];
        res += M[c][cur];
        M[c][cur + val[c]]++;
    }
    cout << res << endl;

    return 0;
}