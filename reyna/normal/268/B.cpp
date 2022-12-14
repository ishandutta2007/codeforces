#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int counter = 0;
	for(int i = n-1;i>0;i--){
		counter += i*(n-i);
	}
	cout << counter+n;
	
}