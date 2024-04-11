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

int a[200];

int main(){
	//freopen("balls.in", "r", stdin);
	//freopen("balls.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	int sum1 = 0, sum2 = 0, ans = 1;
	for(int i = 0; i < n; i++){
		sum2 += a[i];
	}
	for(int i = 0; i < n; i++){
		sum1 += a[i];
		sum2 -= a[i];
		if(sum1 > sum2){
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}