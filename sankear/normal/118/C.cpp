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

const int inf = (int)1e9;

int sz[20];
char s[20000], bs[20000], cs[20000];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d\n%s", &n, &k, s);
	for(int i = 0; i < n; i++){
		sz[s[i] - '0']++;
	}
	for(int i = 0; i < 10; i++){
		if(sz[i] >= k){
			printf("0\n%s\n", s);
			return 0;
		}
	}
	int ans = inf;
	int all = 1 << 10;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(i == j){
				continue;
			}
			for(int z = 0; z < all; z++){
				if((z & (1 << i)) == 0 && (z & (1 << j)) == 0){
					int sum = sz[i];
					for(int h = 0; h < 10; h++){
						if((z & (1 << h)) > 0){
							sum += sz[h];
						}
					}
					if(k - sum <= sz[j]){
						int res = 0;
						for(int h = 0; h < 10; h++){
							if((z & (1 << h)) > 0){
								res += sz[h] * abs(i - h);
							}
						}
						res += max(k - sum, 0) * abs(i - j);
						if(res <= ans){
							for(int h = 0; h <= n; h++){
								cs[h] = s[h];
							}
							for(int h = 0; h < n; h++){
								if((z & (1 << (cs[h] - '0'))) > 0){
									cs[h] = '0' + i;
								}
							}
							int doit = k - sum;
							if(doit > 0){
								if(i < j){
									for(int h = 0; h < n; h++){
										if(cs[h] - '0' == j){
											cs[h] = '0' + i;
											doit--;
											if(doit == 0){
												break;
											}
										}
									}
								}
								else{
									for(int h = n - 1; h >= 0; h--){
										if(cs[h] - '0' == j){
											cs[h] = '0' + i;
											doit--;
											if(doit == 0){
												break;
											}
										}
									}
								}
							}
							if(res < ans || strcmp(cs, bs) == -1){
								ans = res;
								for(int h = 0; h <= n; h++){
									bs[h] = cs[h];
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n%s\n", ans, bs);
	return 0;
}