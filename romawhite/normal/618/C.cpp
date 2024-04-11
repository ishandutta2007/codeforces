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
#include <cassert>

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
const Int INF2 = 1LL * INF * INF;
const int MAX = 1007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

bool Cmp(pair< PII, int> a , pair< PII, int> b)
{
	if (1LL * a.first.first * b.first.second < 1LL * a.first.second * b.first.first) return 1;
	if (1LL * a.first.first * b.first.second > 1LL * a.first.second * b.first.first) return 0;
	return a < b;
}

int main()
{
	//freopen("in.txt" , "r" , stdin);
	//freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	vector<pair<PII,int> > A;
	FOR(i,0,n)
	{
		int x , y;
		scanf("%d%d" , &x , &y);
		A.push_back(MP(MP(x, y), i));
	}
	sort(ALL(A));

	vector<pair< PII, int> > B;

	FOR(i,1,n)
	{
		B.push_back(MP(MP(A[i].first.first - A[0].first.first , A[i].first.second - A[0].first.second) , A[i].second));
	}

	sort(ALL(B) , Cmp);

	FOR(i,1,B.size())
	{
		if (1LL * B[i].first.first * B[0].first.second != 1LL * B[i].first.second * B[0].first.first)
		{
			cout << A[0].second + 1 << ' ' << B[0].second + 1 << ' ' << B[i].second + 1 << endl;
			return 0;
		}
	}

    return 0;
}