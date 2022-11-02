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

const int inf = (int)1e9;

char s[100100];
char r[100];
bool bad[30][30];
int d[100100][30];

int main(){
	//freopen("tests.in", "r", stdin);
	//freopen("tests.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%s %d", s, &k);
	for(int i = 0; i < k; i++){
		scanf("%s", r);
		bad[r[0] - 'a'][r[1] - 'a'] = bad[r[1] - 'a'][r[0] - 'a'] = true;
	}
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			d[i][j] = -inf;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			if(i > 0){
				d[i][j] = max(d[i][j], d[i - 1][j]);
			}
			if(j == s[i] - 'a'){
				d[i][j] = max(d[i][j], 1);
				if(i > 0){
					for(int z = 0; z < 26; z++){
						if(!bad[z][j]){
							d[i][j] = max(d[i][j], d[i - 1][z] + 1);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		ans = max(ans, d[n - 1][i]);
	}
	ans = n - ans;
	printf("%d\n", ans);
	return 0;
}