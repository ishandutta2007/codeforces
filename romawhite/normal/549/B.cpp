#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

string s[107];

int a[107][107];
int b[107];
int c[107];

int main()
{
    //freopen("in.txt","r",stdin);

    int n;
    cin >> n;

    FOR(i,0,n)
    {
        cin >> s[i];
    }

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            a[j][i] = s[i][j] - '0';
        }
    }

    FOR(i,0,n)
    {
        cin >> b[i];
    }


    vector<int> res;

    while (1)
    {
        bool ch = 0;
        FOR(i,0,n)
        {
            int cnt = 0;
            FOR(j,0,n)
            {
                cnt += a[i][j] * c[j];
            }
            if (cnt == b[i])
            {
                c[i] = 1;
                ch = 1;
                break;
            }
        }
        if (!ch) break;
    }


    FOR(i,0,n)
    {
        if (c[i])
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    FOR(i,0,res.size())
    {
        cout << res[i] + 1 << ' ' ;
    }
    cout << endl;




    return 0;
}