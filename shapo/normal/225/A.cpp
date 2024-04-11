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

#define maxn 105
#define maxk 7

int n;
int x;
int a[maxn], b[maxn];
bool used[maxk];

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i], &b[i]);
	int c, d;
	x = 7 - x;
	for(int i = 1; i <= n; ++i){
		memset(used, 0, sizeof(used));
		used[a[i]] = used[7 - a[i]] = 1;
		used[b[i]] = used[7 - b[i]] = 1;
		if(used[x]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}