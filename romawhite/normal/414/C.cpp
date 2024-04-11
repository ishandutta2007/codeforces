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
const int MAX = 100;
const int MAX2 = 7000;
const Int BASE = 1000000007;

const int MOD = 1000000007;

int a[1 << 21];
int b[1 << 21];
int c[1 << 21];
Int B[25];
Int C[25];

int temp[1 << 21];

void merge1(int l , int r , int h)
{
	if (h == 0)
	{
		return;
	}
	int m = (l + r) / 2;
	merge1(l , m , h - 1);
	merge1(m + 1 , r , h - 1);

	Int inv = 0;
	int t = 0;
	int j = m + 1;
	FOR(i,l,m + 1)
	{
		while (j <= r && b[j] < b[i])
		{
			temp[t++] = b[j++];
		}
		inv += j - (m + 1);
		temp[t++] = b[i];
	}

	while (j <= r)
	{
		temp[t++] = b[j++];
	}

	FOR(i,l,r + 1)
		b[i] = temp[i - l];

	B[h] += inv;
}

void merge2(int l , int r , int h)
{
	if (h == 0)
	{
		return;
	}
	int m = (l + r) / 2;
	merge2(l , m , h - 1);
	merge2(m + 1 , r , h - 1);

	Int inv = 0;
	int t = 0;
	int j = m + 1;
	FOR(i,l,m + 1)
	{
		while (j <= r && c[j] > c[i])
		{
			temp[t++] = c[j++];
		}
		inv += j - (m + 1);
		temp[t++] = c[i];
	}

	while (j <= r)
	{
		temp[t++] = c[j++];
	}
	FOR(i,l,r + 1)
		c[i] = temp[i - l];
	C[h] += inv;
}

bool SW[25];

int main()
{
	int n;
	cin >> n;

	FOR(i,0,1 << n)
	{
		scanf("%d" , &a[i]);
		b[i] = c[i] = a[i];
	}

	merge1(0,(1 << n) - 1 , n);
	merge2(0,(1 << n) - 1 , n);

	Int r = 0;
	FOR(i,0,n + 1)
		r += B[i];

	//FOR(i,0,n + 1)
	//	cout << B[i] << ' ' << C[i] << endl;

	int m;
	cin >> m;
	FOR(i,0,m)
	{
		int q;
		scanf("%d" , &q);
		FOR(j,0,q + 1)
		{
			if (SW[j] == 0)
			{
				r -= B[j];
				r += C[j];
			}
			else
			{
				r -= C[j];
				r += B[j];
			}
			SW[j] ^= 1;
		}

		printf("%I64d\n" , r);
	}

	return 0;
}