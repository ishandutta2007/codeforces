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

#define maxn 100500

using namespace std;

int n, k;
int a[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int i = n - 1;
	while(i >= 1 && a[i] == a[i + 1])--i;
	if(i >= k)
		printf("-1\n");
	else
		printf("%d\n", i);
	return 0;
}