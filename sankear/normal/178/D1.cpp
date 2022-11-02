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

#define pb push_back

int n, need;
int a[20];
int val[20][20];
vector <int> lst[66000];

inline bool find(int sum, int mask){
	for(int i = 0; i < n * n; i++){
		if(a[i] == sum && (mask & (1 << i)) != 0){
			return true;
		}
	}
	return false;
}

inline bool check(int x, int mask){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += val[x][i];
	}
	if(sum != need){
		return false;
	}
	if(x == n - 2){
		int sum = 0;
		for(int i = 0; i < n - 1; i++){
			sum += val[i][i];
		}
		if(!find(need - sum, mask)){
			return false;
		}
		sum = 0;
		for(int i = 0; i < n - 1; i++){
			sum += val[i][n - i - 1];
		}
		if(!find(need - sum, mask)){
			return false;
		}
		for(int i = 0; i < n; i++){
			sum = 0;
			for(int j = 0; j < n - 1; j++){
				sum += val[j][i];
			}
			if(!find(need - sum, mask)){
				return false;
			}
		}
	}
	return true;
}

void gen(int x, int y, int mask){
	if(x >= n){
		for(int i = 0; i < n; i++){
			int sum = 0;
			for(int j = 0; j < n; j++){
				sum += val[i][j];
			}
			if(sum != need){
				return;
			}
			sum = 0;
			for(int j = 0; j < n; j++){
				sum += val[j][i];
			}
			if(sum != need){
				return;
			}
		}
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += val[i][i];
		}
		if(sum != need){
			return;
		}
		sum = 0;
		for(int i = 0; i < n; i++){
			sum += val[i][n - i - 1];
		}
		if(sum != need){
			return;
		}
		printf("%d\n", need);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(j > 0){
					printf(" ");
				}
				printf("%d", val[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	for(int i = 0; i < (int)lst[mask].size(); i++){
		val[x][y] = a[lst[mask][i]];
		if(y == n - 1 && !check(x, mask ^ (1 << lst[mask][i]))){
			continue;
		}
		if(y == n - 1){
			gen(x + 1, 0, mask ^ (1 << lst[mask][i]));
		}
		else{
			gen(x, y + 1, mask ^ (1 << lst[mask][i]));
		}
	}
}

int main(){
	//freopen("difference.in", "r", stdin);
	//freopen("difference.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	need = 0;
	for(int i = 0; i < n * n; i++){
		scanf("%d", &a[i]);
		need += a[i];
	}
	need /= n;
	int all = (1 << (n * n));
	for(int i = 0; i < all; i++){
		for(int j = 0; j < n * n; j++){
			if((i & (1 << j)) != 0){
				lst[i].pb(j);
			}
		}
	}
	gen(0, 0, all - 1);
	return 0;
}