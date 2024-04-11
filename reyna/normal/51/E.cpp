//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 7e2 + 20;
long long mat[6][Maxn][Maxn];
long long *ptr[6][Maxn];
int n,m;
int Mul(long long *Mat1[Maxn],long long *Mat2[Maxn],long long *AnsMat[Maxn]){
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			for(int k = 0; k < n;k++){
				AnsMat[i][j] += Mat1[i][k] * Mat2[k][j];
			}
		}
	}
}
int main(){
	n = 700;
	m = 0;
	cin >> n >> m;
	for(int i = 0; i < m;i++){
		int u,v;
		cin >> u >> v;
		mat[1][--u][--v] = 1;
		mat[1][v][u] = 1;
	}
	for(int i = 0; i < n;i++)
		ptr[1][i] = mat[1][i];
	for(int i = 0; i < n;i++)
		ptr[2][i] = mat[2][i];
	for(int i = 0; i < n;i++)
		ptr[3][i] = mat[3][i];
	for(int i = 0; i < n;i++)
		ptr[5][i] = mat[5][i];
	Mul(ptr[1],ptr[1],ptr[2]);
	Mul(ptr[1],ptr[2],ptr[3]);
	for(int i = 0; i < n;i++){
		for(int k = 0; k < n;k++){
			mat[5][i][i] += mat[2][i][k] * mat[3][k][i];
		}
	}
	long long ans = 0;
	for(int i = 0; i < n;i++){
		ans += mat[5][i][i] - mat[3][i][i] * (mat[2][i][i]-1) * 5;
//		cerr << mat[5][i][i] << endl;
	}
//	long long minus = 0;
//	for(int i = 0; i < n;i++){
//		minus += mat[3][i][i] * (mat[2][i][i]-1) * 5;
////		cerr << mat[3][i][i] << " " << mat[2][i][i] << endl;
//	}
//	ans -= minus;
	ans/=2;
	cout << ans / 5 << endl;
	return 0;
}