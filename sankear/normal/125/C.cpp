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

int sz[200];
int lst[200][20000];

int main(){
	//cerr << (sizeof(sz) + sizeof(lst)) / 1024 / 1024 << endl;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n;
	scanf("%d", &n);
	int k;
	for(int i = 2; i <= n; i++){
		if((i * (i - 1)) / 2 > n){
			break;
		}
		k = i;
	}
	int cur = 0;
	for(int i = 0; i < k - 1; i++){
		for(int j = i + 1; j < k; j++){
			lst[i][sz[i]++] = cur;
			lst[j][sz[j]++] = cur++;
		}
	}
	printf("%d\n", k);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < sz[i]; j++){
			if(j > 0){
				printf(" ");
			}
			printf("%d", lst[i][j] + 1);
		}
		printf("\n");
	}
	return 0;
}