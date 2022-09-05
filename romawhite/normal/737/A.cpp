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
const int MAX = 100007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int n , k , s , t;
VI A , B;
vector<PII> C;

bool F(int x)
{
	int sum = 0;

	for(int i = 0; i < SZ(B); ++i)
	{
		if (x < B[i]) return 0;

		sum += 2 * B[i] - min(x - B[i] , B[i]);
	}
	return sum <= t;
}

int main() {

	//freopen("in.txt" , "r" , stdin);

	cin >> n >> k >> s >> t;

	vector<PII> CC;
	FOR(i,0,n)
	{
		int x , y;
		scanf("%d%d" , &x , &y);
		CC.push_back(MP(y , x));
	}
	sort(ALL(CC));
	FOR(i,0,SZ(CC))
	{
		while (SZ(C) && C.back().second >= CC[i].second) C.pop_back();
		if (C.empty() || CC[i].first > C.back().first) C.push_back(CC[i]);
	}

	FOR(i,0,k)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}
	A.push_back(0);
	A.push_back(s);
	sort(ALL(A));
	A.resize(unique(ALL(A)) - A.begin());
	FOR(i,0,SZ(A) - 1)
	{
		B.push_back(A[i + 1] - A[i]);
	}

	int L = 0;
	int R = SZ(C) - 1;

	if (!F(C[R].first))
	{
		cout << -1 << endl;
		return 0;
	}

	while (R - L > 1)
	{
		int X = (L + R) / 2;
		if (F(C[X].first))
			R = X;
		else L = X;
	}
	if (F(C[L].first)) R = L;

	cout << C[R].second;

    return 0;
}