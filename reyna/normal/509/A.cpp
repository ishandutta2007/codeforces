//In the name of God
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long ans = 1;
	long long div = 1;
	for(int i = 1; i < n;i++){
		div *= i;
	}
	for(int i = n; i < 2 * n - 1;i++){
		ans *= i;
	}
	cout << ans / div << endl;
	return 0;
}