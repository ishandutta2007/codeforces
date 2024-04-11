#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 300000

using namespace std;

int n, res;
int p1[maxn], p2[maxn];

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)scanf("%d", &p1[i]);
	for(int i = 1; i <= n; ++i)scanf("%d", &p2[i]);

	res = 0;
	int cur = 0;
	for(int i = 1; i <= n; ++i)if(p1[cur + 1] == p2[i])++cur;

	res = n - cur;
	printf("%d\n", res);

	return 0;
}