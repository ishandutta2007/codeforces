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

bool used[200];
int a[200][4], b[200][4];
int ok[200], c[200];
int lst[200][200], d[200][200];
char s[200][40];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n, t;
	scanf("%d %d", &n, &t);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			scanf("%d %d", &a[i][j], &b[i][j]);
		}
	}
	int m;
	scanf("%d\n", &m);
	for(int i = 0; i < m; i++){
		scanf("%s\n%d\n", s[i], &c[i]);
	}
	int op = 0;
	int num = 0;
	int sz = 0;
	while(true){
		for(int i = 0; i < n; i++){
			int cur = t;
			while(cur > 0){
				int need = max(1, c[num] - (a[i][op] + b[i][1 - op]) - d[i][num]);
				if(cur >= need){
					cur -= need;
					lst[i][ok[i]++] = num;
					used[num] = true;
					sz++;
					if(sz == m){
						for(int ii = 0; ii < n; ii++){
							printf("%d", ok[ii]);
							for(int j = 0; j < ok[ii]; j++){
								printf(" %s", s[lst[ii][j]]);
							}
							printf("\n");
						}
						return 0;
					}
					while(used[num]){
						num = (num + 1) % m;
					}
					continue;
				}
				d[i][num] += cur;
				num = (num + 1) % m;
				while(used[num]){
					num = (num + 1) % m;
				}
				break;
			}
		}
		op = 1 - op;
	}
	return 0;
}