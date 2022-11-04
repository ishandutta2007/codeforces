#include<bits/stdc++.h>

using namespace std;

#define M 1000005

const long long MX = 1000005;

long long f[MX], mark[10], unit[10];

void init(){
	long long i, j;
	
	unit[0] = 1;
	for(i = 1; i < 6; i ++) unit[i] = unit[i - 1] * 10;
	
	for(i = 1; i < MX; i ++){
		long long x = i, r;
		for(j = 0; j < 6; j ++){
			r = x % 10;
			if(r % 3 == 0) f[i] += mark[j] * (r / 3);
			x /= 10;
		}
	}
}

int main(){
	
//	freopen("in.txt", "r", stdin);
	
	long long n, k, q, i, j, num;
	
	cin >> k;
	
	for(i = 0; i < 6; i ++) cin >> mark[i];
	k = (k - 1) * 3;
	
	init();
	
	for(long long cnt = k, _cn = 1, id = 1; cnt > 0; _cn *= 2, id ++){
		long long cn = min(cnt, _cn);
		for(j = 0; j < 6; j ++){
			for(num = MX - 1; num >= cn * 3 * unit[j]; num --){
				f[num] = max(f[num], f[num - cn * 3 * unit[j]] + cn * mark[j]);
			}
		}
		cnt -= cn;
	}
	
	cin >> q;
	
	while(q --){
		cin >> n;
		cout << f[n] << endl;
	}
	
	return 0;
}