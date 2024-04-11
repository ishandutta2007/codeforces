//In the name of God
#include <iostream>
using namespace std;
const long long Maxn = 123;
long long mat[Maxn][Maxn];
long long diff[Maxn][Maxn];
long long diff2[Maxn][Maxn];
long long res[Maxn];
long long a[Maxn];
long long b[Maxn];
int main(){
	long long n,m;
	cin >> n >> m;
	long long k = 2e9+3;
	for(long long i = 0; i < n;i++){
		for(long long j = 0; j < m;j++){
			cin >> mat[i][j];
		}
	}
	for(long long i = 0; i < n;i++){
		for(long long j = 0; j < m;j++){
			if(j)
			diff[i][j] = mat[i][j] - mat[i][j-1];
			if(i)
			diff2[i][j] = mat[i][j] - mat[i-1][j];
		}
	}
	for(long long j = 1; j < m;j++){
		long long Min = 1e9+2;
		long long Max = -1e9-2;
		for(long long i = 0; i < n;i++){
			Min = min(Min,diff[i][j]);
			Max = max(Max,diff[i][j]);
		}
		if(Min != Max)
			res[j] = Max - Min;
	}
	for(long long i = 1; i < m;i++){
		if(res[i] && k != 2e9+3 && res[i] != k && res[i] % k){
			cout << "NO" << endl;
			return 0;
		}else if(res[i]){
			k = min(res[i],k);
		}
	}for(long long j = 1; j < n;j++){
		long long Min = 1e9+2;
		long long Max = -1e9-2;
		for(long long i = 0; i < m;i++){
			Min = min(Min,diff2[j][i]);
			Max = max(Max,diff2[j][i]);
		}
		if(Min != Max)
			res[j] = Max - Min;
	}
	for(long long i = 1; i < n;i++){
		if(res[i] && k != 2e9+3 && res[i] != k && res[i] % k){
			cout << "NO" << endl;
			return 0;
		}else if(res[i]){
			k = min(res[i],k);
		}
	}
	for(long long j = 0; j < m;j++)
		b[j] = mat[0][j];
	a[0] = 0;
	for(long long i = 1; i < n;i++){
		a[i] = mat[i][0] - mat[i-1][0] + a[i-1];
		while(a[i] < 0)
			a[i] += k;
	}
	for(long long i = 0; i < n;i++)
		for(long long j = 0; j < m;j++){
			if(mat[i][j] >= k){
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
	cout << k << endl;
	for(long long i = 0; i < n;i++)
		cout << a[i] << ' ';
	cout << endl;
	for(long long i = 0; i < m;i++)
		cout << b[i] << ' ';
	cout << endl;
	return 0;
}