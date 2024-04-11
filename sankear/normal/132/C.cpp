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

char s[200];
bool can[51][101][300][2];

int main(){
	//cerr << sizeof(can) / 1024 / 1024 << endl;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%s\n%d", s, &n);
	int len = strlen(s);
	can[0][0][len + 1][0] = true;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < len; j++){
			for(int z = -len; z <= len; z++){
				if(can[i][j][z + len + 1][0]){
					for(int h = 0; h <= n - i; h++){
						if(h % 2 == 0){
							if(s[j] == 'T'){
								can[i + h][j + 1][z + len + 1][1] = true;
							}
							else{
								can[i + h][j + 1][z + 1 + len + 1][0] = true;
							}
						}
						else{
							if(s[j] == 'T'){
								can[i + h][j + 1][z + 1 + len + 1][0] = true;
							}
							else{
								can[i + h][j + 1][z + len + 1][1] = true;
							}
						}
					}
				}
				if(can[i][j][z + len + 1][1]){
					for(int h = 0; h <= n - i; h++){
						if(h % 2 == 0){
							if(s[j] == 'T'){
								can[i + h][j + 1][z + len + 1][0] = true;
							}
							else{
								can[i + h][j + 1][z - 1 + len + 1][1] = true;
							}
						}
						else{
							if(s[j] == 'T'){
								can[i + h][j + 1][z - 1 + len + 1][1] = true;
							}
							else{
								can[i + h][j + 1][z + len + 1][0] = true;
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = -len; i <= len; i++){
		if(can[n][len][i + len + 1][0] || can[n][len][i + len + 1][1]){
			ans = max(ans, abs(i));
		}
	}
	printf("%d\n", ans);
	return 0;
}