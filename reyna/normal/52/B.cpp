//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1010;
int row[Maxn];
int col[Maxn];
string mat[Maxn];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n;i++){
		cin >> mat[i];
		for(int j = 0; j < m;j++){
			if(mat[i][j] == '*'){
				row[i]++;
				col[j]++;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			if(mat[i][j] == '*'){
				ans += (row[i]-1) * (col[j]-1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}