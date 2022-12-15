#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long M = 107;

long long matrix[M][M], a[M][M], tmp[M][M];
long long m;

void fast_pow(long long exp){
	if(exp == 1){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				a[i][j] = matrix[i][j];
			}
		}

		return ;
	}

	if(exp & 1){
		fast_pow(exp - 1);

		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				tmp[i][j] = a[i][j];
				a[i][j] = 0;
			}
		}

		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < m; k++){
					a[i][j] += (tmp[i][k] * matrix[k][j]) % mod;
					if(a[i][j] >= mod){
						a[i][j] -= mod;
					}
				}
			}
		}

		return ;
	}

	fast_pow(exp / 2);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			tmp[i][j] = a[i][j];
			a[i][j] = 0;
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < m; k++){
				a[i][j] += (tmp[i][k] * tmp[k][j]) % mod;
				if(a[i][j] >= mod){
					a[i][j] -= mod;
				}
			}
		}
	}

	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n >> m;

	matrix[0][0] = 1;
	matrix[0][m-1] = 1;

	for(int i = 1; i < m; i++){
		matrix[i][i-1] = 1;
	}

	fast_pow(n);

	cout << a[0][0] << "\n";

	return 0;
}