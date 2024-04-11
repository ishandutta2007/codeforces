#include <iostream>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int a,b;
	cin >> a >> b;
	if(a == 1 && b==1){
		cout << 1 << "/" << 1 << endl;
		return 0;
	}
	cout << (6-max(a,b)+1)/gcd(6-max(a,b)+1,6) << "/" << 6/gcd(6-max(a,b)+1,6) << endl;
}