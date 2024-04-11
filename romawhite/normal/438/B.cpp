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
#include <functional>
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
const int MOD = 1000000007;

int p[100007];
int sz[100007];

int find_set(int v)
{
	if (v == p[v]) return v;
	return p[v] = find_set(p[v]);
}

Int res = 0;

void union_sets(int a, int b, int cost)
{
	a = find_set(a);
	b = find_set(b);
	if (a == b) return;

	res += 2LL * sz[a] * sz[b] * cost;
	
	if (sz[a] < sz[b])
		swap(a,b);
	p[b] = a;
	sz[a] += sz[b];
}

int a[100007];

int main()
{
	int n,m;
	cin >> n >> m;

	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
	}

	vector<pair<int, pair<int,int> > > e;

	FOR(i,0,m)
	{
		int A, B;
		scanf("%d %d", &A , &B);
		e.push_back(MP(min(a[A - 1],a[B - 1]) , MP(A - 1, B - 1)));
	}

	sort(ALL(e));
	reverse(ALL(e));

	FOR(i,0,n)
	{
		p[i] = i;
		sz[i] = 1;
	}



	FOR(i,0,e.size())
	{
		union_sets(e[i].second.first , e[i].second.second , e[i].first);
	}

	printf("%.7f\n" , 1.0 * res / (1LL * n * (n - 1)));

    return 0;
}