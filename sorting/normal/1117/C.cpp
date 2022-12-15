#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e9;
const long long N = 1e5 + 7;

long long wx[N], wy[N];
long long n;

long long x1, y1, x2, y2;

int check(long long mid){
	long long x_diff = x1 - x2;
	long long y_diff = y1 - y2;

	x_diff += mid * wx[n];
	y_diff += mid * wy[n];

	for(int i = 1; i <= n; i++){
		if((abs(x_diff + wx[i]) + abs(y_diff + wy[i])) <= mid*n + i){
			return i;
		}
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x1 >> y1 >> x2 >> y2;

	cin >> n;

	string s;

	cin >> s;

	wx[0] = 0;
	wy[0] = 0;

	for(long long i = 0; i < n; i++){
		wx[i+1] = wx[i];
		wy[i+1] = wy[i];

		if(s[i] == 'U'){
			wy[i+1]++;
		}
		if(s[i] == 'D'){
			wy[i+1]--;
		}
		if(s[i] == 'L'){
			wx[i+1]--;
		}
		if(s[i] == 'R'){
			wx[i+1]++;
		}
	}

	long long l = 0, r = inf, mid;

	while(l != r){
		mid = (l + r) / 2;

		//cout << check(mid) << " - " << mid << "\n";

		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	if(!check(l)){
		cout << "-1\n";
	}
	else{
		cout << n * l + check(l) << "\n";
	}

	return 0;
}