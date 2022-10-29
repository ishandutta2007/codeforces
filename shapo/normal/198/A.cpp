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

long long k, b, n, t, res;

int main(){
	ios_base::sync_with_stdio(false);

	cin >> k >> b >> n >> t;
	if(k == 1){
		long long z = 1 + n * b;
		cout << max(0LL, (z - t + b - 1) / b) << '\n';
		return 0;
	}
	long long to_div = (k - 1) * t + b, nado = k - 1 + b;
	long long mong = to_div / nado;
	//cerr << mong << '\n';
	int st = 0;
	long long cur = 1;
	while(cur <= mong / k){
		cur *= k;
		++st;
	}
	cout << max((n - st), 0LL) << '\n';

	return 0;
}