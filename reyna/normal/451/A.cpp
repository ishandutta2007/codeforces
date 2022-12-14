#include <iostream>
using namespace std;
int n,m;
int main(){
	cin >> n >> m;
	if(n <= m && n % 2 == 1){
		cout << "Akshat";
	}else if(m <= n && m % 2 == 1){
		cout << "Akshat";
	}else{
		cout << "Malvika";
	}
}