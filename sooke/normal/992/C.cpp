#include <iostream>
#define M(x) ((x) % 1000000007)

using namespace std;

long long n , k , x , inv;

long long Pow(long long d , long long p){
	long long res = 1;
	d = M(d);
	while(p > 0){
		if(p & 1)
			res = M(res * d);
		d = M(d * d);
		p >>= 1;
	}
	return res;
}

int main(){
	cin >> n >> k;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	x = M(M(n) * Pow(2 , k));
	inv = Pow(Pow(2 , k) , 1000000005);
	cout << M(M(M(M(x * 2 - Pow(2 , k) + 1) + 1000000007) * Pow(2 , k)) * inv) << endl;
	return 0;
}

// By Sooke.
// CF992C Nastya and a Wardrobe.