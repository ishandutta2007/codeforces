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

vector<pair<pair<Int ,Int> , int> > a;

const int INF = 1000000000;



int main()
{
	//freopen("in.txt" , "r" , stdin);
	int n,k;
	string s;
	cin >> n >> k >> s;

	if (k - 1 <= n - k)
	{
		FOR(i,0,k - 1)
			cout << "LEFT\n";
		FOR(i,0,n)
		{
			cout << "PRINT " << s[i] << endl;
			if (i != n - 1)
			{
				cout << "RIGHT\n";
			}
		}
	}
	else
	{
		FOR(i,0,n - k)
			cout << "RIGHT\n";
		RFOR(i,n,0)
		{
			cout << "PRINT " << s[i] << endl;
			if (i != 0)
			{
				cout << "LEFT\n";
			}
		}
	}
	return 0;
}