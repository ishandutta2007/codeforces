#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())


int gcd(int a,int b) {
	while(b)
		a %= b, swap(a,b);
	return a;
}

nagai lcm(nagai a, nagai b){
	return a * b / gcd(a,b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>cnt(200001);
	for(auto&x:a)cin >> x, ++cnt[x];
	nagai res = 1;
	for(int ans = 200000; ans >= 1; --ans) {
		int c = 0;
		for(int i = ans; i < cnt.size(); i += ans) {
			c += cnt[i];
		}
		if (c >= n - 1)
			res = lcm(res, ans);
	}
	cout << res << '\n';
	return 0;
}