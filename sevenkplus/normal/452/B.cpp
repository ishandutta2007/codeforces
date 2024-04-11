#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int n,m;
set<PII> A;

void add(int x, int y) {
	if (x < 0 || x > n || y < 0 || y > m) return;
	A.insert(mp(x,y));
}

double dis(PII x, PII y) {
	return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
}

typedef set<PII>::iterator SIT;

int main()
{
	cin >> n >> m;
	add(0,0);
	add(0,1);
	add(1,0);
	add(1,1);
	add(n,m);
	add(n-1,m);
	add(n-1,m-1);
	add(n,m-1);
	add(0,m);
	add(1,m);
	add(0,m-1);
	add(1,m-1);
	add(n,0);
	add(n,1);
	add(n-1,0);
	add(n-1,1);
	double S = -1;
	PII p0,p1,p2,p3;
	for (SIT i = A.begin(); i != A.end(); i ++)
	for (SIT j = A.begin(); j != A.end(); j ++)
	for (SIT k = A.begin(); k != A.end(); k ++)
	for (SIT l = A.begin(); l != A.end(); l ++) {
		if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
		double T = dis(*i,*j)+dis(*j,*k)+dis(*k,*l);
		if (T > S) {
			p0 = *i;
			p1 = *j;
			p2 = *k;
			p3 = *l;
			S = T;
		}
	}
	printf ("%d %d\n",p0.fi,p0.se);
	printf ("%d %d\n",p1.fi,p1.se);
	printf ("%d %d\n",p2.fi,p2.se);
	printf ("%d %d\n",p3.fi,p3.se);
	return 0;
}