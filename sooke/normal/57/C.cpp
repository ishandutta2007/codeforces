#include <iostream>
#define M(x) ((x) % 1000000007)

using namespace std;

long long n , a = 1 , b = 1 , inv;

inline long long Pow(long long d , long long p){
	long long res = 1;
	while(p > 0){
		if(p & 1)
			res = M(res * d);
		d = M(d * d);
		p >>= 1;
	}
	return res;
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n * 2 ; i++)
		a = M(a * i);
	for(int i = 1 ; i <= n ; i++){
		b = M(b * i);
		b = M(b * i);
	}
	inv = Pow(b , 1000000005);
	a = M(a * inv);
	cout << M(a - n + 1000000007) << endl;
	return 0;
}

// By Sooke.
// CF57C Array.