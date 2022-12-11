#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	ll n;
	cin >> n;
	ll st = 1;
	ll c = 0;
	while (c < n)
	{
		c += st * 5;
		st *= 2;
	}
	st /= 2;
	c -= st * 5;
	
	switch (((n - c)% st == 0)?((n - c) / st - 1):((n - c) / st))
	{
		case 0:printf("Sheldon");
		       break;
		case 1:printf("Leonard");
		       break;
		case 2:printf("Penny");
		       break;
		case 3:printf("Rajesh");
		       break;
		case 4:printf("Howard");
		       break;
	}
	return 0;
}