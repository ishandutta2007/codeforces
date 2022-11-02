#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

ll a[200200];
int lst[200200];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
		sum += a[i];
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		if(a[i] * (n - 1) == sum - a[i]){
			lst[sz++] = i;
		}
	}
	printf("%d\n", sz);
	for(int i = 0; i < sz; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", lst[i] + 1);
	}
	printf("\n");
	return 0;
}