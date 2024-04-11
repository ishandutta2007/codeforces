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
#include <bitset>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1007;
const int MOD = 1000000007;

int p[MAX];
int sz[MAX];

int cnt = 1;

multiset<int> S;

int Find(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = Find(p[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) {
		cnt ++;
		return;
	}
	p[b] = a;
	S.erase(S.find(-sz[a]));
	S.erase(S.find(-sz[b]));
	sz[a] += sz[b];
	S.insert(-sz[a]);
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, d;
	cin >> n >> d;
	FOR(i,0,n)
	{
		p[i] = i;
		sz[i] = 1;
		S.insert(-1);
	}

	FOR(i,0,d) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		Union(a, b);
		int res = 0;
		int c = cnt;
		for(int x: S) {
			res -= x;
			-- c;
			if (c == 0)
				break;
		}
		cout << res - 1 << endl;
	}


    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}