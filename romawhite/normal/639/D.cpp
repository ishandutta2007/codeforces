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
const int MAX = 250007;
const int MAX2 = 2000000;
const int BASE = 10;
const int ST = 1000000007;
const int CNT = 100;

int a[MAX];

int Next(int val, int t)
{
	while (val % 5 != t) ++val;
	return val;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);

	int n , k , b , c;
	cin >> n >> k >> b >> c;
	b = min(b , 5 * c);

	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
		a[i] += INF;
	}

	Int res = 1LL * INF * INF;

	sort(a , a + n);

	FOR(t,0,5)
	{
		multiset<Int> S;
		Int add = 0;

		Int sum = 0;
		Int last = t;

		FOR(i,0,n)
		{
			Int val = Next(a[i] , t);
			add += (val - last) / 5 * b;
			sum += (Int)S.size() * (val - last) / 5 * b;
			sum += (val - a[i]) * c;
			S.insert((val - a[i]) * c - add);
			if (S.size() > k)
			{
				Int V = *S.rbegin();
				S.erase(S.find(V));
				sum -= V + add;
			}

			//cout << S.size() << ' ' << sum << endl;

			if (S.size() == k)
			{
				res = min(res , sum);
			}
			last = val;
		}
		//cout << endl;
	}

	cout << res << endl;

	return 0;
}