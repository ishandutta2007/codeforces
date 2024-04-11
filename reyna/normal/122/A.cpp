#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n;i++){
		if(n%i == 0){
			int j = i;
			while(1){
				if(j % 10 == 4){
					if(j > 9){
						j/=10;
					}else{
						cout << "YES";
						return 0;
					}
				}else if(j%10 == 7){
					if(j > 9){
						j/=10;
					}else{
						cout << "YES";
						return 0;
					}
				}else{
					break;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}