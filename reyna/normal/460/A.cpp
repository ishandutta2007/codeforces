#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int m;
	cin >> m;
	int counter = n;
	int a = 1;
	int c = 0;
	while(counter != 0){
		counter--;
		if(a % m == 0){
			counter++;
		}
		c++;
		a++;
	}
	cout << c << endl;
	return 0;
}