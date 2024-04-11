#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int n, m, res;

int main(){
	scanf("%d%d", &n, &m);
	res = 0;
	for(int a = 0; a <= m; ++a)
		for(int b = 0; b <= n; ++ b)
			if(a * a + b == n && b * b + a == m)++res;
	printf("%d\n", res);
	return 0;
}