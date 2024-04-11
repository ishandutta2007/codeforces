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
const int MAX = 100007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

PII res[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);

	int n , w , h;
	cin >> n >> w >> h;

	vector<pair<PII, pair<PII, PII> > > A;

	FOR(i,0,n)
	{
		int g , p , t;
		scanf("%d%d%d" , &g , &p , &t);
		t -= p;
		PII a , b;
		if (g == 1)
		{
			a = MP(p , 0);
			b = MP(p , -h);
		}
		else
		{
			a = MP(0 , -p);
			b = MP(w, -p);
		}
		A.push_back(MP(MP(t , i) , MP(a , b)));
	}
	sort(ALL(A));
	for(int i = 0; i < SZ(A);)
	{
		int add = 1;
		while (i + add < SZ(A) && A[i + add].first.first == A[i].first.first) ++ add;
		vector<pair<PII, int> > B;
		vector<PII> C;
		FOR(j,i,i + add)
		{
			B.push_back(MP(A[j].second.first , A[j].first.second));
			C.push_back(A[j].second.second);
		}
		sort(ALL(B));
		sort(ALL(C));
		FOR(j,0,SZ(B))
		{
			res[B[j].second] = C[j];
		}
		i += add;
	}

	FOR(i,0,n)
	{
		printf("%d %d\n" , res[i].first , -res[i].second);
	}

	return 0;
}