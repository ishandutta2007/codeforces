#include <iostream>
using namespace std;
int n,m;
const int maxn = 100;
string arr[maxn];
int main(){
	cin >> n >> m;
	for(int i = 0; i < n;i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			if(arr[i][j] == '.' && (i+j)% 2 == 0){
				arr[i][j] = 'W';
			}else if(arr[i][j] == '.' && (i+j)% 2 == 1){
				arr[i][j] = 'B';
			}
		}
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
}