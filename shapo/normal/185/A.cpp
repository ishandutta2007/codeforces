#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;

const long long pp = 1000000007;
long long n, a;

long long pow2(const long long &x){
	long long res = 1, tmp = 2;
	long long cur = x;
	while(cur > 0){
		if(cur % 2 == 0){
			tmp = (tmp * tmp) % pp;
			cur /= 2;
		}
		else{
			res = (res * tmp) % pp;
			--cur;
		}
	}
	return res;
}

int main(){

	cin >> n;
	a = pow2(n);
	//cout << a << endl;
	a = ((a * (a + 1)) % pp * (pp + 1) / 2) % pp;
	cout << a << "\n";

	return 0;
}