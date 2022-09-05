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
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 1000007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

bool isPrime(int x)
{
	for(int i = 2; i < x; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}

int main()
{
	//freopen("in.txt" , "r" , stdin);

	VI a;
	FOR(i,2,51)
	{
		if (isPrime(i))
			a.push_back(i);
	}

	int cnt = 0;

	VI b;
	b.push_back(4);
	b.push_back(9);
	b.push_back(25);
	b.push_back(49);

	FOR(i,0,SZ(b))
	{
		cout << b[i] << endl;
		string s;
		cin >> s;
		if (s == "yes")
		{
			cout << "composite" << endl;
			return 0;
		}
	}


	FOR(i,0,SZ(a))
	{
		cout << a[i] << endl;
		string s;
		cin >> s;
		if (s == "yes") ++cnt;
	}

	if (cnt <= 1)
	{
		cout << "prime" << endl;
	}
	else
	{
		cout << "composite" << endl;
	}



    return 0;
}