#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int x, n;
	cin >> x;
	if(x == 3){
		cout << "5\n";
		return 0;
	}
	for(int i = 1; i <= 100; i += 2){
		if((i * i + 1) / 2 >= x){
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}