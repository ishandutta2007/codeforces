#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << (n + 2) * 2 / 3 - 1 << endl;
	if(n == 1){
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	int d = (n + 1) / 3;
	for(int i = 1; i < d; i++) cout << i << " " << d - i << endl;
	for(int i = 1; i <= d; i++) cout << d + i - 1 << " " << d * 2 - i << endl;
	for(int i = 0; i < (n - 2) % 3; i++) cout << n - i << " " << n - i << endl;
}