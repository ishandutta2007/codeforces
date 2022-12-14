//In the name of God
#include <iostream>
using namespace std;
int main(){
	long long n,x,y;
	cin >> n >> x >> y;
	if(y < n){
		cout << -1 << endl;
		return 0;
	}
	if((y - n + 1) * (y - n + 1) + n - 1 < x){
		cout << -1 << endl;
		return 0;
	}
	cout << (y - n + 1) << endl;
	for(int i = 0; i < n-1;i++){
		cout << 1 << endl;
	}
	return 0;
}