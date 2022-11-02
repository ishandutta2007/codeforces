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

int a[1010];

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int res = 1;
		int j = i - 1;
		while(j >= 0 && a[j] <= a[j + 1]){
			res++;
			j--;
		}
		j = i + 1;
		while(j < n && a[j] <= a[j - 1]){
			res++;
			j++;
		}
		ans = max(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}