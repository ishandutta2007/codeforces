#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	double counter = 0;
	for(int i = 0; i < n;i++){
		int a;
		cin >> a;
		counter+=a;
	}
	cout << counter/n;
}