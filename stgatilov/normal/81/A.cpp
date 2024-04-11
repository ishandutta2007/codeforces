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

char str[1<<20];
char expr[1<<20];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%s", &str);

	int l = 0;
	for (int i = 0; str[i]; i++) {
		if (l && str[i] == expr[l-1]) l--;
		else expr[l++] = str[i];
		expr[l] = 0;
//		printf("%s\n", expr);
	}
	printf("%s\n", expr);

	return 0;
}