#include <iostream>
using namespace std;
long long F[1000];
int main(){
	F[0] = 0;
	F[1] = 1;
	int n;
	cin >> n;
	if(n == 2){
		cout << 1 << " " << 1 << " " << 0;
		return 0;
	}
	if(n == 1 ){
		cout << 1 << " " << 0 << " " << 0;
		return 0;
	}
	if(n ==  0){
		cout << 0 << " " << 0 << " " << 0;
		return 0;
	}
	for(int i = 2; i < 1000; i++){
		F[i] = F[i-1]+F[i-2];
		if(F[i] == n){
			cout << F[i-1] << " " << F[i-3] << " " << F[i-4] << endl;
			break;
		}
	}
	return 0;
	
}