#include <iostream>
#define Inf 5e18

using namespace std;

void ExGcd(long long x , long long y , long long &gcd , long long &a , long long &b){
	if(y == 0){
		a = 1 , b = 0 , gcd = x;
		return;
	}
	ExGcd(y , x % y , gcd , b , a);
	b -= a * (x / y);
}

long long a , b , c , gcd , soa , sob;

int main(){
	cin >> a >> b >> c;
	ExGcd(a , b , gcd , soa , sob);
	if(c % gcd != 0){
		cout << -1 << endl;
		return 0;
	}
	soa *= -c / gcd;
	sob *= -c / gcd;
	if(soa >= -Inf && soa <= Inf && sob >= -Inf && sob <= Inf)
		cout << soa << " " << sob << endl;
	else
		cout << -1 << endl;
	return 0;
}

// By Sooke.
// CF7C Line.