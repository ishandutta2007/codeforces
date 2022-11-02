#include<bits/stdc++.h>
using namespace std;

#define N 404000

typedef long long LL;

char s[N];

int n, gas[N];
vector <int> dp;

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	scanf("%s", s);
	int len = strlen(s);

	for(int i = 0; i < len; i ++){
		int sum = 0;
		for(int j = i; j < len; j ++){
			sum += s[j] - '0';
			gas[sum] ++;
		}
	}

	if(n == 0){
		LL ans = 0;
		ans += 1ll * gas[0] * (len * (len + 1) - gas[0]);
		cout << ans << endl;
		return 0;
	}

	int x = n;
	dp.push_back(1);
	for(int i = 2; i <= x; i ++){
		if(x % i == 0){
			int tmp = 1, sz = dp.size();
			while(x % i == 0){
				x /= i;
				tmp = tmp * i;
				for(int j = 0; j < sz; j ++) dp.push_back(dp[j] * tmp);
			}
		}
	}
	if(x > 1){
		int sz = dp.size();
		for(int j = 0; j < sz; j ++) dp.push_back(dp[j] * x);
	}

	//for(auto y : dp) printf("%d ", y); puts("");



	LL ans = 0;
	for(auto y : dp){
		if(y < N && n / y < N){
			ans += 1ll * gas[y] * gas[n / y];
		}
	}
	cout << ans << endl;
}