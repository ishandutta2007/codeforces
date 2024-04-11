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
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int cnta[27];
int cntb[27];
int cntc[27];

char buf[MAX];

int main()
{
    //freopen("in.txt" , "r", stdin);

    scanf("%s" , buf);
    string a = buf;
    scanf("%s" , buf);
    string b = buf;
    scanf("%s" , buf);
    string c = buf;

    FOR(i,0,a.size())
    {
        cnta[a[i] - 'a']++;
    }
    FOR(i,0,b.size())
    {
        cntb[b[i] - 'a']++;
    }
    FOR(i,0,c.size())
    {
        cntc[c[i] - 'a']++;
    }

    int mx = 0;
    int cb = 0;

    FOR(i,0,a.size() + 1)
    {
        int bnd = INF;
        FOR(j,0,26)
        {
            Int rem = cnta[j] - 1LL * i * cntb[j];
            if (rem < 0) bnd = -1;
            else
            {
                if (cntc[j] > 0)
                {
                    bnd= min(bnd , (int)rem / cntc[j]);
                }
            }
        }
        if (bnd == -1) continue;
        if (bnd + i > mx)
        {
            mx = bnd + i;
            cb = i;
        }
    }

    //cout << cb << ' ' << mx << endl;

    FOR(j,0,26)
    {
        cnta[j] -= cb * cntb[j];
        cnta[j] -= (mx - cb) * cntc[j];
    }

    FOR(i,0,cb)
    {
        printf("%s" , b.c_str());
    }
    FOR(i,0,mx-cb)
    {
        printf("%s" , c.c_str());
    }

    FOR(i,0,26)
    {
        FOR(j,0,cnta[i])
        {
            printf("%c" , (char)('a' + i));
        }
    }
    cout << endl;

    return 0;
}