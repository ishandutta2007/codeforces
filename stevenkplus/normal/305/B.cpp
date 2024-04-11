#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> ans;

void go(ll a, ll b) {
	if (b == 0) return;
	ll f = a / b;
	ll ret = a % b;
	ans.push_back(f);
	go(b, ret);
}
int main() {
	ll a, b;
	cin >> a >> b;

	go(a, b);

	int N;
	cin >> N;

	int len = int(ans.size());
	if (N < len) printf("NO\n");
	else {
		for(int i = 0; i < len - 1; ++i) {
			ll tmp;
			cin >> tmp;
			if (tmp != ans[i]) {
				printf("NO\n");
				return 0;
			}
		}
		ll sum = 0;
		for(int i = len - 1; i < N; ++i) {
			ll tmp;
			cin >> tmp;
			sum += tmp;
		}
		if (ans[len-1] ==sum){ 
		printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}