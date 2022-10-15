#include <iostream>
#include <cmath>
#define P 1000000007

using namespace std;

long long n , k;

inline long long Euler(long long d){
	long long tmp = d;
	for(long long i = 2 ; i * i <= tmp ; i++)
		if(tmp % i == 0){
			d = d / i * (i - 1);
			while(tmp % i == 0)
				tmp /= i;
		}
	if(tmp > 1)
		d = d / tmp * (tmp - 1);
	return d;
}

int main(){
	cin >> n >> k;
	k = (k + 1) / 2;
	while(k > 0 && n > 1){
		k = k - 1;
		n = Euler(n);
	}
	cout << n % P << endl;
	return 0;
}

// By Sooke.
// CF776E The Holmes Children.