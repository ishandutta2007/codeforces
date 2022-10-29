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

long long l, r;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> l >> r;
	long long res = 0;
	for(long long i = 1; i <= 9; ++i){
		if(i >= l && i <= r)++res;
		if(11 * i >= l && 11 * i <= r)++res;
		long long st = 1;
		//printf("i = %lld, res = %lld\n", i, res);
		for(int j = 1; j <= 17; ++j){
			if(i * (100 * st + 1) > r)break;
			long long ll = -1, rr = 10 * st, mm;
			while(ll < rr - 1){
				mm = (ll + rr) / 2;
				if(i * (100 * st + 1) + mm * 10 > r)rr = mm;
				else ll = mm;
			}
			long long r1 = ll, l1;
			ll = -1; rr = 10 * st;
			while(ll < rr - 1){
				mm = (ll + rr) / 2;
				if(i * (100 * st + 1) + mm * 10 < l)ll = mm;
				else rr = mm;
			}
			l1 = rr;
			res = res + max(0LL, r1 - l1 + 1);
			st = st * 10;
		}
	}

	cout << res << '\n';

	return 0;
}