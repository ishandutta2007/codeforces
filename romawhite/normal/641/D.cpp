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
#include <fstream>

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
const int MAX = 100007;
const int MAX2 = 2000000;
const int BASE = 10;
const int ST = 1000003;
const int CNT = 100;

const int MOD = 1000000007;

double mn[MAX];
double mx[MAX];

double a[MAX];
double b[MAX];
double sa[MAX];
double sb[MAX];

int main()
{
	//freopen("out.txt" , "w" , stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("puzzle.in", "r", stdin);
	//freopen("puzzle.out", "w", stdout);

	int n;
	cin >> n;

	/*FOR(i,0,n)
	{
		scanf("%lf" , &a[i]);
	}
	FOR(i,0,n)
	{
		scanf("%lf" , &b[i]);
	}
	double Sb = 0;
	double Sa = 0;
	FOR(i,0,n)
	{
		Sb += b[i];
		mx[i] += a[i] * Sb + b[i] * Sa;
		mn[i] = a[i] * (1 - Sb) + b[i] * (1 - Sa);
		Sa += a[i];
	}*/


	FOR(i,0,n)
	{
		scanf("%lf" , &mx[i]);
	}
	FOR(i,0,n)
	{
		scanf("%lf" , &mn[i]);
	}

	/*FOR(i,0,n)
	{
		printf("%.10f " , mx[i]);
	}
	printf("\n");
	FOR(i,0,n)
	{
		printf("%.10f " , mn[i]);
	}
	printf("\n");
	printf("\n");*/

	FOR(i,0,n)
	{
		double c = mn[i] + mx[i];
		double A = 1;
		double B = -c + sa[i] - sb[i];
		double C = - c * sa[i] + mx[i];
		double D = sqrt(max(0., B * B - 4 * A * C));
		double X1 = (-B + D) / (2 * A);
		double X2 = (-B - D) / (2 * A);
		double val1 = (X1 < 0.5 ? min(0., -X1) : min(0., X1 - 1));
		double val2 = (X2 < 0.5 ? min(0., -X2) : min(0., X2 - 1));

		a[i] = X1;
		b[i] = c - a[i];
		a[i] = max(0., min(1. , a[i]));
		b[i] = max(0., min(1. , b[i]));
		sa[i + 1] = sa[i] + a[i];
		sb[i + 1] = sb[i] + b[i];
	}

	FOR(i,0,n)
	{
		printf("%.10f " , a[i]);
	}
	printf("\n");
	FOR(i,0,n)
	{
		printf("%.10f " , b[i]);
	}
	printf("\n");


	return 0;
}