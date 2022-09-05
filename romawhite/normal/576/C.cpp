#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
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

vector<pair<int , int> > A[1007];

int main()
{

    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;

    FOR(i,0,n)
    {
        int x , y;
        scanf("%d%d" , &x , &y);
        A[x / 1000].push_back(MP(y , i));
    }

    FOR(i,0,1007)
    {
        sort(ALL(A[i]));
        if (i % 2) reverse(ALL(A[i]));
        FOR(j,0,A[i].size())
        {
            printf("%d " , A[i][j].second + 1);
        }
    }

    cout << endl;

    return 0;
}