#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

int solve(int x){
	int res = 0;

	for(int j = 1; j < x; j++){
		res = max(gcd(x & j, x ^ j), res); 
	}

	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;

	mp[3] =  1;
	mp[7] =  1;
	mp[15] =  5;
	mp[31] =  1;
	mp[63] =  21;
	mp[127] =  1;
	mp[255] =  85;
	mp[511] =  73;
	mp[1023] =  341;
	mp[2047] =  89;
	mp[4095] =  1365;
	mp[8191] =  1;
	mp[16383] =  5461;
	mp[32767] =  4681;
	mp[65535] =  21845;
	mp[131071] =  1;
	mp[262143] =  87381;
	mp[524287] =  1;
	mp[1048575] =  349525;
	mp[2097151] =  299593;
	mp[4194303] =  1398101;
	mp[8388607] =  178481;
	mp[16777215] =  5592405;
	mp[33554431] =  1082401;

	cin >> q;

	while(q--){
		int x, res = 0, y;
		bool b = false;

		cin >> x;
		
		y = x;

		while(x > 0){
			res *= 2;
			if(x % 2 == 0){
				b = true;
			}
			res++;
			x /= 2;
		}

		x = y;

		if(b){
			cout << res<< "\n";
		}
		else{
			cout << mp[res] << "\n";
		}

		//cout << solve(x) << " sol\n";
	}

	return 0;
}