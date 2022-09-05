#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 2000000;
const int BASE = 10;
const int ST = 1000000007;
const int CNT = 100;

int A[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);

	int n , k , q;
	scanf("%d%d%d" , &n , &k , &q);
	set<int> S;

	FOR(i,0,n)
	{
		scanf("%d" , &A[i]);
	}

	FOR(i,0,q)
	{
		int x , y;
		scanf("%d%d" , &x , &y);
		if (x == 1)
		{
			--y;
			S.insert(A[y]);
			if (S.size() > k)
			{
				S.erase(S.begin());
			}
		}
		else
		{
			--y;
			if (S.find(A[y]) != S.end())
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}

	return 0;
}