#include <iostream>
using namespace std;
int main(){
	int n;
	int x;
	cin >> n;
	cin >> x;
	int counter = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		counter+=a;
	}
	if(counter == 0){
		cout << 0;
		return 0;
	}
	if(counter < 0){
		counter = -counter;
	}
	if(counter > 0){
		for(int i = 1; i <= n; i++){
			counter -= x;
			if(counter <= 0){
				cout << i;
				return 0;
			}
		}
	}
}