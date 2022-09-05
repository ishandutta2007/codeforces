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
const int MAX = 200007;
const int MAX2 = 2000;
const int BASE = 1000000000;

int a[MAX];
int L[MAX];
int R[MAX];
int res[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }

    vector<pair<int,int> > Q;
    FOR(i,0,n)
    {
        while(Q.size() && a[i] <= Q.back().first) Q.pop_back();
        if (Q.size())
        {
            L[i] = Q.back().second + 1;
        }
        Q.push_back(MP(a[i] , i));
    }
    Q.clear();
    RFOR(i,n,0)
    {
        while(Q.size() && a[i] <= Q.back().first) Q.pop_back();
        if (Q.size())
        {
            R[i] = Q.back().second - 1;
        }
        else
        {
            R[i] = n - 1;
        }
        Q.push_back(MP(a[i] , i));
    }

    FOR(i,0,n)
    {
        res[R[i] - L[i]] = max(res[R[i] - L[i]] , a[i]);
    }
    RFOR(i,n,1)
    {
        res[i - 1] = max(res[i - 1] , res[i]);
    }

    FOR(i,0,n)
    {
        printf("%d " , res[i]);
    }
    printf("\n");

    return 0;
}