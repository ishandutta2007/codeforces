/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 343A
 */
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if (a < b)
		return gcd(b, a);
	else if (a % b == 0)
		return a / b;
	else
		return a / b + gcd(b, a % b);
}

int main(){
	long long a, b;

	cin >> a >> b;
	cout << gcd(a, b);

	return 0;
}