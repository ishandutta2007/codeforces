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

int a[10];
bool used[100100];

int main(){
	//freopen("tests.in", "r", stdin);
	//freopen("tests.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for(int i = 0; i < 4; i++){
		scanf("%d", &a[i]);
	}
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 4; i++){
		for(int j = a[i] - 1; j < n; j += a[i]){
			used[j] = true;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(used[i]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}