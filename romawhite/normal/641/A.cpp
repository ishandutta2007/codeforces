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
const int MAX = 500000;
const int MAX2 = 3500000;
const int BASE = 1000000000;
const int CNT = 20000;

int n;
char S[MAX];
int D[MAX];
int U[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
    #endif

    cin >> n;
    scanf("%s", S);
    FOR (i,0,n)
    	scanf("%d", &D[i]);

    int cur = 0;
    while (1)
    {
    	if (cur < 0 || cur >= n)
    	{
    		printf("FINITE\n");
    		return 0;
    	}
    	if (U[cur] == 1)
    	{
    		printf("INFINITE\n");
    		return 0;
    	}
    	U[cur] = 1;
    	if (S[cur] == '<')
    		cur -= D[cur];
    	else
    		cur += D[cur];
    }


    return 0;
}