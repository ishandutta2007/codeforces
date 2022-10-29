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

using namespace std;

int num[5];
int n, cur, res;

int max(const int &a, const int &b){if(a > b)return a; return b;}

int main(){
	for(int i = 0; i < 5; ++i)num[i] = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &cur);
		++num[cur];
	}
	res = 0;
	res = res + num[4];
	res = res + num[3];
	num[1] = max(0, num[1] - num[3]);
	res = res + (num[2] / 2) + (num[2] % 2);
	if(num[2] % 2 == 1)num[1] = max(0, num[1] - 2);
	res = res + (num[1] + 3) / 4;
	printf("%d\n", res);
	return 0;
}