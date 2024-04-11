//In the name of God
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int cur = 0;
	for(int i = 1; i < n;i++){
		cur += i;
		cur %= n;
		cout << cur + 1 << ' ';
	}
	return 0;
}