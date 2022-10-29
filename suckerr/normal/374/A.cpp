#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int inf = 100000000;

int n, m, a, b, x, y;

int solve(int xx, int yy) {
	
	if (abs(x - xx) % a != 0 || abs(y - yy) % b != 0)
		return inf;
	
	int s = abs(x - xx) / a, t = abs(y - yy) / b;
	if (s % 2 != t % 2)
		return inf;
	s = t = max(s, t);
	
	if (s && x - a < 1 && x + a > n)
		return inf;
	
	if (t && y - b < 1 && y + b > m)
		return inf;
	
	return s;
}

int main() {
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
	
	int ans = inf;
	
	ans = min(ans, solve(1, 1));
	ans = min(ans, solve(n, 1));
	ans = min(ans, solve(1, m));
	ans = min(ans, solve(n, m));
	
	if (ans == inf)
		printf("Poor Inna and pony!\n");
	else
		printf("%d\n", ans);
	
	return 0;
}