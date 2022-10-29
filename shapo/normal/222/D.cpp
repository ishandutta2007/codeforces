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

int n, x;
int a[maxn], b[maxn];
int mn, mx;

int ok(int x){
	int k = n, res = 0;
	for(int i = 1; i <= n && k >= 1; ++i){
		while(k >= 1 && a[i] + b[k] < x)--k;
		if(k >= 1){
			++res;
			--k;
		}
	}
	return res;
}

bool cmp(const int &a, const int &b){return(a > b);}

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	mn = 1;
	mx = ok(x);
	printf("%d %d\n", mn, mx);
	return 0;
}