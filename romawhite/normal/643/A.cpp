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
const int MAX = 7000;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n;
int A[MAX];
int C[MAX];
int R[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    cin >> n;
    FOR (i,0,n)
    {
    	int x;
    	cin >> x;
    	-- x;
    	A[i] = x;
    }
    FOR (i,0,n)
    {
    	int cnt = -1, id = -1;
    	FOR (j,0,n)
    		C[j] = 0;
    	FOR (j,i,n)
    	{
    		++ C[A[j]];
    		if (C[A[j]] > cnt)
    		{
    			cnt = C[A[j]];
    			id = A[j];
    		}
    		else
    		if (C[A[j]] == cnt && A[j] < id)
    		{
    			id = A[j];
    		}
    		++ R[id];
    	}
    }

    FOR (i,0,n)
    	cout << R[i] << ' ';


    return 0;
}