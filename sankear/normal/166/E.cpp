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

const ll MOD = (ll)(1e9 + 7);

ll a[10][10], b[10][10], c[10][10];

void calc(int n){
	if(n == 1){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				b[i][j] = a[i][j];
			}
		}
		return;
	}
	if(n % 2 == 0){
		calc(n / 2);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				c[i][j] = 0;
				for(int z = 0; z < 4; z++){
					c[i][j] = (c[i][j] + b[i][z] * b[z][j]) % MOD;
				}
			}
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				b[i][j] = c[i][j];
			}
		}
		return;
	}
	calc(n - 1);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			c[i][j] = 0;
			for(int z = 0; z < 4; z++){
				c[i][j] = (c[i][j] + b[i][z] * a[z][j]) % MOD;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			b[i][j] = c[i][j];
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i != j){
				a[i][j] = 1;
			}
		}
	}
	calc(n);
	cout << b[0][0] << endl;
	return 0;
}