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
#include <queue>
#include <deque>
#include <functional>

using namespace std;

const int size = 22;
const int all = (1 << size) - 1;

int num[all + 10], a[all + 10];

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= all; i++){
		num[i] = -1;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		num[a[i]] = i;
	}
	for(int i = 0; i <= all; i++){
		if(num[i] == -1){
			for(int j = 0; j < size; j++){
				if((i & (1 << j)) != 0){
					int mask = i ^ (1 << j);
					if(num[mask] != -1){
						num[i] = num[mask];
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		int ans = num[all - a[i]];
		if(ans != -1){
			ans = a[ans];
		}
		printf("%d", ans);
	}
	printf("\n");
	return 0;
}