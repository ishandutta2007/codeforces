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

int n;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	set<string> amu;
	for (int i = 0; i<n; i++) {
		char b1[16], b2[16];
		if (i) scanf("%s", b1);
		scanf("%s%s", b1, b2);
		string curr = string() + b1[0] + b1[1] + b2[1] + b2[0];

		string cmin = curr;
		for (int i = 0; i<10; i++) {
			curr = curr.substr(1) + curr[0];
			if (cmin > curr) cmin = curr;
		}
		amu.insert(cmin);
	}
	printf("%d\n", amu.size());
	return 0;
}