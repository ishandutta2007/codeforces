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

using namespace std;

typedef long long ll;
typedef long double ld;

const int step = (int)1e9;

bool can[10000010];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
	int a, b, mod;
	scanf("%d %d %d", &a, &b, &mod);
	if(mod == 1){
		printf("2\n");
		return 0;
	}
	for(int i = 0; i <= min(b, mod - 1); i++){
		can[(mod - i) % mod] = true;
	}
	for(int i = 0; i <= min(a, mod - 1); i++){
		if(!can[((ll)i * step) % mod]){
			printf("1 %09d\n", i);
			return 0;
		}
	}
	printf("2\n");
	return 0;
}