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

int a[100];

int main(){
	//freopen("balls.in", "r", stdin);
	//freopen("balls.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	k--;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0 && a[i] >= a[k]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}