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
#include <assert.h>
#include <time.h>


#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
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
const int MAX = 200007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int A[MAX];

int main() {

	//freopen("in.txt" , "r" , stdin);

	int n , s;
	cin >> n >> s;
	-- s;
	int res = 0;

	FOR(i,0,n)
	{
		int x;
		scanf("%d" , &x);
		if (i == s && x != 0)
		{
			++ res;
			x = 0;
		}
		if (i != s && x == 0)
		{
			x = n;
		}

		A[x] ++;
	}

	int add = INF;

	if (n == 1)
	{
		cout << res << endl;
		return 0;
	}

	int c1 = 0;
	int c2 = 1;

	FOR(h,1,n)
	{
		c1 += (A[h] == 0);
		c2 += A[h];
		add = min(add , max(c1 , n - c2));
	}

	cout << res + add << endl;
    return 0;
}