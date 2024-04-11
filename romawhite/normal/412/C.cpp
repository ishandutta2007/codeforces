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
const double Pi = acos(-1.0);

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;

int a[100007];

int main()
{
	//freopen("in.txt" , "r" , stdin);
	int n;
	FILL(a,-1);
	cin >> n;
	int l;
	FOR(i,0,n)
	{
		string s;
		cin >> s;
		l = s.size();
		FOR(j,0,s.size())
		{
			if (s[j] == '?')
				continue;
			if (a[j] == -1)
				a[j] = s[j] - 'a';
			else
			{
				if (a[j] >= 0)
				{
					if (a[j] != s[j] - 'a')
						a[j] = -2;
				}
			}
		}
	}

	FOR(i,0,l)
	{
		if (a[i] == -1)
			cout << 'a';
		if (a[i] == -2)
			cout << '?';
		if (a[i] >= 0)
		{
			cout << char('a' + a[i]);
		}
	}
	cout << endl;

	return 0;
}