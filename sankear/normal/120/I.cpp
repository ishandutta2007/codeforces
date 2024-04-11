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

int mask[20], num[20];
int cnt[300];
char s[200200];
int sum1[200200], sum2[200200];

inline void init(){
	mask[0] |= 1 << 0;
	mask[0] |= 1 << 1;
	mask[0] |= 1 << 2;
	mask[0] |= 1 << 3;
	mask[0] |= 1 << 4;
	mask[0] |= 1 << 6;
	mask[1] |= 1 << 1;
	mask[1] |= 1 << 3;
	mask[2] |= 1 << 4;
	mask[2] |= 1 << 1;
	mask[2] |= 1 << 5;
	mask[2] |= 1 << 2;
	mask[2] |= 1 << 6;
	mask[3] |= 1 << 4;
	mask[3] |= 1 << 1;
	mask[3] |= 1 << 5;
	mask[3] |= 1 << 3;
	mask[3] |= 1 << 6;
	mask[4] |= 1 << 0;
	mask[4] |= 1 << 5;
	mask[4] |= 1 << 1;
	mask[4] |= 1 << 3;
	mask[5] |= 1 << 4;
	mask[5] |= 1 << 0;
	mask[5] |= 1 << 5;
	mask[5] |= 1 << 3;
	mask[5] |= 1 << 6;
	mask[6] |= 1 << 4;
	mask[6] |= 1 << 0;
	mask[6] |= 1 << 5;
	mask[6] |= 1 << 3;
	mask[6] |= 1 << 6;
	mask[6] |= 1 << 2;
	mask[7] |= 1 << 4;
	mask[7] |= 1 << 1;
	mask[7] |= 1 << 3;
	mask[8] |= 1 << 4;
	mask[8] |= 1 << 1;
	mask[8] |= 1 << 3;
	mask[8] |= 1 << 6;
	mask[8] |= 1 << 2;
	mask[8] |= 1 << 0;
	mask[8] |= 1 << 5;
	mask[9] |= 1 << 4;
	mask[9] |= 1 << 1;
	mask[9] |= 1 << 3;
	mask[9] |= 1 << 6;
	mask[9] |= 1 << 0;
	mask[9] |= 1 << 5;
	int all = 1 << 7;
	for(int i = 0; i < all; i++){
		for(int j = 0; j < 7; j++){
			if((i & (1 << j)) > 0){
				cnt[i]++;
			}
		}
	}
	for(int i = 0; i < 10; i++){
		num[i] = 0;
		for(int j = 1; j < 10; j++){
			if(cnt[mask[i] & mask[j]] > cnt[mask[i] & mask[num[i]]]){
				num[i] = j;
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  init();
	scanf("%s", s);
	int n = strlen(s);
	int k = n / 2;
	for(int i = k; i < n; i++){
		sum1[i] = sum1[i - 1] + cnt[mask[s[i - k] - '0'] & mask[s[i] - '0']];
	}
	for(int i = 0; i < k; i++){
		sum2[i] = (i > 0 ? sum2[i - 1] : 0) + cnt[mask[s[i] - '0'] & mask[num[s[i] - '0']]];
	}
	int need = sum1[n - 1];
	for(int i = n - 1; i >= k; i--){
		for(int j = s[i] - '0' + 1; j < 10; j++){
			int res = sum1[i - 1] + cnt[mask[s[i - k] - '0'] & mask[j]] + sum2[n - k - 1] - sum2[i - k];
			if(res > need){
				s[i] = '0' + j;
				res = sum1[i - 1] + cnt[mask[s[i - k] - '0'] & mask[j]];
				for(int z = i + 1; z < n; z++){
					for(int h = 0; h < 10; h++){
						int cur = res + cnt[mask[s[z - k] - '0'] & mask[h]] + sum2[n - k - 1] - sum2[z - k];
						if(cur > need){
							s[z] = '0' + h;
							res += cnt[mask[s[z - k] - '0'] & mask[h]];
							break;
						}
					}
				}
				printf("%s\n", s);
				return 0;
			}
		}
	}
	int best = 0;
	for(int i = 1; i < 10; i++){
		if(cnt[mask[i] & mask[num[i]]] > cnt[mask[best] & mask[num[best]]]){
			best = i;
		}
	}
	for(int i = k - 1; i >= 0; i--){
		for(int j = s[i] - '0' + 1; j < 10; j++){
			int res = (i > 0 ? sum2[i - 1] : 0) + cnt[mask[j] & mask[num[j]]] + (k - i - 1) * cnt[mask[best] & mask[num[best]]];
			if(res > need){
				s[i] = '0' + j;
				res = (i > 0 ? sum2[i - 1] : 0) + cnt[mask[j] & mask[num[j]]];
				for(int z = i + 1; z < k; z++){
					for(int h = 0; h < 10; h++){
						int cur = res + cnt[mask[h] & mask[num[h]]] + (k - z - 1) * cnt[mask[best] & mask[num[best]]];
						if(cur > need){
							s[z] = '0' + h;
							res += cnt[mask[h] & mask[num[h]]];
							break;
						}
					}
				}
				for(int z = 0; z < k; z++){
					sum2[z] = (z > 0 ? sum2[z - 1] : 0) + cnt[mask[s[z] - '0'] & mask[num[s[z] - '0']]];
				}
				res = 0;
				for(int z = k; z < n; z++){
					for(int h = 0; h < 10; h++){
						int cur = res + cnt[mask[s[z - k] - '0'] & mask[h]] + sum2[n - k - 1] - sum2[z - k];
						if(cur > need){
							s[z] = '0' + h;
							res += cnt[mask[s[z - k] - '0'] & mask[h]];
							break;
						}
					}
				}
				printf("%s\n");
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}