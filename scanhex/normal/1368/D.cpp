#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<nagai>a(n);
	for(auto&x:a)cin>>x;
	int lg=23;
	vector<int>c(lg);
	for(auto&x:a){
		for(int i=0;i<lg;++i)
			if (x >> i & 1)
				++c[i];
	}
	nagai ans = 0;
	for(int i=0;i<n;++i){
		nagai x=0;
		for(int j=0;j<lg;++j)
			if (c[j] > 0) {
				--c[j];
				x ^= 1 << j;
			}
		ans += x * x;
	}
	cout << ans << '\n';
	return 0;
}