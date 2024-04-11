#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;

const ll inf = (ll)1e17;

bool can1[100100], can2[100100];
int a[100100], b[100100], lst[100100];
ll sum[100100], s[100100], val[100100];

int main(){
	//freopen("tea.in", "r", stdin);
	//freopen("tea.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + b[i];
	}
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		can1[i] = true;
	}
	val[n + 1] = -inf;
	for(int i = n; i > 0; i--){
		val[i] = max(val[i + 1], sum[i - 1] - s[i - 1]);
	}
	for(int i = 1; i <= n; i++){
		if(val[i + 1] > sum[i - 1] - s[i - 1]){
			can1[i] = false;
		}
	}
	val[0] = -inf;
	for(int i = 1; i <= n; i++){
		val[i] = max(val[i - 1], sum[i - 1] - s[i - 1]);
	}
	for(int i = 1; i <= n; i++){
		if(val[i] > sum[i - 1] - s[i - 1] - sum[n] + s[n]){
			can1[i] = false;
		}
	}
	for(int i = 1; i <= n; i++){
		can2[i] = true;
	}
	val[0] = inf;
	for(int i = 1; i <= n; i++){
		val[i] = min(val[i - 1], sum[i - 1] - s[i]);
	}
	for(int i = 1; i <= n; i++){
		if(sum[i - 1] - s[i] > val[i - 1]){
			can2[i] = false;
		}
	}
	val[n + 1] = inf;
	for(int i = n; i > 0; i--){
		val[i] = min(val[i + 1], sum[i - 1] - s[i]);
	}
	for(int i = 1; i <= n; i++){
		if(sum[i - 1] - s[i] + sum[n] - s[n] > val[i]){
			can2[i] = false;
		}
	}
	int sz = 0;
	for(int i = 1; i <= n; i++){
		if(can1[i] || can2[i]){
			lst[sz++] = i;
		}
	}
	printf("%d\n", sz);
	if(sz > 0){
		for(int i = 0; i < sz; i++){
			if(i > 0){
				printf(" ");
			}
			printf("%d", lst[i]);
		}
		printf("\n");
	}
	return 0;
}