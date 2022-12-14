//In the name of God
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int x = 0;
	for(int i = 0; i < n;i++){
		string now;
		cin >> now;
		if(now[1] == '+')
			x++;
		else
			x--;
	}
	cout << x << endl;
	return 0;
}