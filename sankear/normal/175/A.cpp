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

typedef long long ll;

const ll maxch = (ll)1e6;
const int inf = (int)1e9;

char s[100];
bool good[100][100];
int val[100][100];
int d[100][4];

int main(){
	//freopen("factory.in", "r", stdin);
	//freopen("factory.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(j - i + 1 > 1 && s[i] == '0'){
				continue;
			}
			ll cur = 0;
			bool fl = true;
			for(int z = i; z <= j; z++){
				cur = cur * 10 + s[z] - '0';
				if(cur > maxch){
					fl = false;
					break;
				}
			}
			if(!fl){
				continue;
			}
			good[i][j] = true;
			val[i][j] = cur;
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			d[i][j] = -inf;
		}
	}
	d[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			for(int z = i; z > 0; z--){
				if(good[z - 1][i - 1] && d[z - 1][j - 1] != -inf){
					d[i][j] = max(d[i][j], d[z - 1][j - 1] + val[z - 1][i - 1]);
				}
			}
		}
	}
	if(d[n][3] == -inf){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", d[n][3]);
	return 0;
}