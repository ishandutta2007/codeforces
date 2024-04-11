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

long long calc(const long long &x, const long long &pow, const long long &pp){
	long long res = 1, tmp = (x % pp);
	long long cur = pow;
	while(cur > 0){
		if(cur % 2 == 0){
			tmp = (tmp * tmp) % pp;
			cur = cur / 2;
		}
		else{
			res = (res * tmp) % pp;
			cur = cur - 1;
		}
	}
	return res;
}

int obr(){
	long long k, l, r, p;
	cin >> k >> l >> r >> p;
	long long ans;
	if(p == 2){
		cout << (1 - (k % 2)) << endl;
		return 0;
	}
	if(k == 1)ans = 2 % p;
	else{
		long long st_l = calc(2, l, p - 1), st_r = calc(2, r + 1, p - 1);
		long long rev_2 = (p + 1) / 2;
		long long ch = (calc(k, st_r, p) + p - 1) % p;
		long long zn = (calc(k, st_l, p) + p - 1) % p;
		if(k % p == 0)zn = ch = p - 1;
		//cout << "st_l = " << st_r << " st_l = " << st_l << endl;
		//cout << "ch = " << ch << " zn = " << zn << endl;
		if(zn == 0){
			ch = calc(2, r - l + 1, p);
		}
		else{
			zn = calc(zn, p - 2, p);
			ch = (ch * zn) % p;
		}
		if(k % 2){
			long long to_div = calc(rev_2, r - l, p);
			ch = (ch * to_div) % p;
		}
		ans = ch;
	}
	cout << ans << endl;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)obr();

	return 0;
}