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

int CNT[MAX];
char s[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("huffman.in" , "r" , stdin);

    int n , k;
    cin >> n >> k;
    scanf("%s" , s);

    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i)
    {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }

    FOR(i,1,n)
    {
        Int L = 1LL * i * k - 1;
        Int R = 1LL * i * (k + 1) - 1;
        R = min(R , 1LL * i + z[i] - 1);
        if (R >= L)
        {
            CNT[L] ++;
            CNT[R + 1]--;
        }
    }

    int cur = 0;
    FOR(i,0,n)
    {
        cur += CNT[i];
        if (cur > 0||k==1) printf("1");
        else printf("0");
    }
    cout << endl;

    return 0;
}