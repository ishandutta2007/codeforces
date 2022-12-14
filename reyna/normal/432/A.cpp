#include <iostream>
using namespace std;
int main(){
	int n,k;
	int counter = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a+k <= 5){
			counter++;
		}
	}
	cout << counter/3;
}