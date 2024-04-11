#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int n;
long long m;

long long pow_pow(int n, long long mod){
	long long res = 1, tmp = 3;
	while(n){
		if(n % 2){
			--n;
			res = (res * tmp) % m;
		}
		n /= 2;
		tmp = (tmp * tmp) % m;
	}
	return (res + m - 1) % m;
}

int main(){
	cin >> n >> m;
	cout << pow_pow(n, m) << "\n";
	return 0;
}