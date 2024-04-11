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

int a[100100], ans[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	bool fl = true;
	for(int i = 0; i < n; i++){
		if(a[i] != 1){
			fl = false;
			break;
		}
	}
	if(fl){
		for(int i = 0; i < n - 1; i++){
			ans[i] = 1;
		}
		ans[n - 1] = 2;
	}
	else{
		ans[0] = 1;
		for(int i = 1; i < n; i++){
			ans[i] = a[i - 1];
		}
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}