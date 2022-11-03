#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
int64 lcm(int a, int b) { return int64(a) * (b / gcd(a, b)); }

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	int a, b;
	scanf("%d%d", &a, &b);
	int64 ab = lcm(a, b);

	int ka = ab / a;
	int kb = ab / b;
	if (a > b) kb--;
	else ka--;

	if (ka == kb) printf("Equal\n");
	else if (ka > kb) printf("Dasha\n");
	else printf("Masha\n");

//	printf("%d %d\n", ka, kb);
	return 0;
}