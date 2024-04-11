#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi		=	acos(-1.0);
const double eps	=	1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

inline int powmod(int x,int t,int base)
{
	if (!t) return 1%base;
	int y=powmod(x,t/2,base);
	y=(LL)y*y%base;
	if (t&1) y=(LL)y*x%base;
	return y;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",(powmod(3,n,m)+m-1)%m);
	return 0;
}