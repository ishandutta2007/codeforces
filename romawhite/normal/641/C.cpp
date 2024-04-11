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
const int MAX = 3000000;
const int MAX2 = 3500000;
const int BASE = 1000000000;
const int CNT = 20000;

int n, m;
int A[MAX];
VI I[MAX];
int P[2];
int S[2];

int main()
{
    #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
    #endif


    cin >> n >> m;
    FOR (i,0,n)
    	A[i] = i;

    P[0] = 0;
    P[1] = 1;
    FOR (i,0,n)
    	if (i % 2 == 0)
    		I[0].PB(i);
    	else
    		I[1].PB(i);

    FOR (i,0,m)
    {
    	int t;
    	scanf("%d", &t);
    	if (t == 1)
    	{
    		int x;
    		scanf("%d", &x);
    		x = (x+n)%n;
    		if (x % 2 == 0)
    		{
    			S[0] = (S[0]-x/2+SZ(I[0]))%SZ(I[0]);
    			S[1] = (S[1]-x/2+SZ(I[1]))%SZ(I[1]);
    		}
    		else
    		{
    			S[0] = (S[0]-x/2+SZ(I[0]))%SZ(I[0]);
    			S[1] = (S[1]-((x+1)/2)+SZ(I[1]))%SZ(I[1]);
    			swap(P[0], P[1]);
    			swap(S[0], S[1]);
    		}
    	}
    	else
    	{
    		swap(P[0], P[1]);
    		swap(S[0], S[1]);
    	}
    }

    FOR (i,0,n)
    {
    	int x;
    	if (i % 2 == 0)
    	{
    		x = I[P[0]][S[0]];
    		S[0] = (S[0] + 1) % SZ(I[P[0]]);
    	}
    	else
    	{
    		x = I[P[1]][S[1]];
    		S[1] = (S[1] + 1) % SZ(I[P[1]]);
    	}
    	printf("%d ", x+1);
    }





    return 0;
}