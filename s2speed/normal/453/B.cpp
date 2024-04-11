#include<bits/stdc++.h>

using namespace std;

#define gcd __gcd

typedef pair<int , int> pint;
typedef double db;

int tav(int n , int k){
	int res = 1;
	while(k > 0){
		if(k & 1) res *= n;
		n *= n;
		k /= 2;
	}
	return res;
}

const int MAX_N = 100 + 20 , md = 1e9 + 7 , MAX_A = 65536;

int dp[MAX_N][MAX_A] , a[MAX_N] , p[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53} , f[MAX_N][MAX_A];
vector<int> s , ans , q[24] , v;

void sq_build(){
	int h = 1;
	while(h < MAX_A){
		s.push_back(h);
		h *= 2;
	}
	s.push_back(3);
	s.push_back(5);
	s.push_back(9);
	s.push_back(6);
	s.push_back(10);
	s.push_back(12);
	s.push_back(7);
	s.push_back(11);
	for(int i = 0 ; i < 16 ; i++){
		int x = p[i] , y = p[i];
		for( ; x < 59 ; ){
			q[i].push_back(x);
			x *= y;
		}
	}
	q[16].push_back(6);
	q[16].push_back(12);
	q[16].push_back(18);
	q[16].push_back(24);
	q[17].push_back(10);
	q[17].push_back(20);
	q[18].push_back(14);
	q[18].push_back(28);
	q[19].push_back(15);
	q[20].push_back(21);
	q[21].push_back(35);
	q[22].push_back(30);
	q[23].push_back(42);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	sq_build();
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	for(int j = 0 ; j < MAX_A ; j++){
		for(int i = 0 ; i <= n ; i++){
			dp[i][j] = 1e8;
			f[i][j] = 1;
		}
	}
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < MAX_A ; j++){
			if(dp[i - 1][j] > 2900){
				continue;
			}
			if(dp[i - 1][j] + a[i] - 1 < dp[i][j]){
				dp[i][j] = dp[i - 1][j] + a[i] - 1;
				f[i][j] = 1;
			}
			int h = 65535 - j;
			for(int k = 0 ; k < 24 ; k++){
				int e = h & s[k];
				if(e == s[k]){
					int o = 330 , ind;
					for(auto u : q[k]){
						if(o > max(a[i] - u , u - a[i])){
							ind = u;
							o = max(a[i] - u , u - a[i]);
						}
					}
					o += dp[i - 1][j];
					e = j | s[k];
					if(dp[i][e] > o){
						dp[i][e] = o;
						f[i][e] = ind;
					}
				}
			}
		}
	}
	int ans = 1e8 , m = 0 , h;
	for(int i = 0 ; i < MAX_A ; i++){
		if(dp[n][i] < ans){
			ans = dp[n][i];
			m = i;
		}
	}
	for(int i = n ; i > 0 ; i--){
		v.push_back(f[i][m]);
		int q = 1;
		h = 0;
		for(int j = 0 ; j < 16 ; j++){
			if(f[i][m] % p[j] == 0){
				h += q;
			}
			q *= 2;
		}
		m -= h;
	}
	reverse(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		cout<<v[i]<<' ';
	}
	cout<<'\n';
	return 0;
}