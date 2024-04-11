#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

pair<LL, LL> Fgas(LL x, LL v){
	if(x <= v * 2 - 2) return make_pair(0, 0);
	LL xx = x / 2, gas1 = 0, gas2 = 0;
	pair<LL, LL> tmp = Fgas(xx, v);
	if(x >= v * 2 - 1) gas1 ++;
	if(x > v * 2 - 1) gas2 ++;
	if(x & 1){
		gas1 += tmp.first * 2;
		gas2 += tmp.first + tmp.second;
		return make_pair(gas1, gas2);
	}
	else{
		gas1 += tmp.first + tmp.second;
		gas2 += tmp.second * 2;
		return make_pair(gas1, gas2);
	}
}

LL n, k;

int main(){
	cin >> n >> k;
	LL st = 1, en = n;
	if(k == 1){
		cout << 1 << endl; return 0;
	}
	if(k == 2){
		cout << n << endl; return 0;
	}
	k -= 2;
	while(st < en - 1){
		LL len = en - st - 1;
		LL mid = (st + en) >> 1;

		if(k == 1ll) { cout << mid << endl; return 0; }

		LL len1 = mid - st - 1, len2 = en - mid - 1;
		LL mn = 1, mx = n;
		while(mn < mx - 1){
			LL center = (mn + mx) >> 1;
			LL gas = Fgas(len, center).first;
			if(gas < k) mx = center;
			else mn = center;
		}
		LL leftgas = Fgas(len1, mn).first, rightgas = Fgas(len2, mx).first;
		LL tot = leftgas + 1 + rightgas;
		if(tot >= k){
			k -= 1 + rightgas;
			en = mid;
		}
		else{
			k -= 1 + leftgas;
			st = mid;
		}
	}
	assert(0);
}