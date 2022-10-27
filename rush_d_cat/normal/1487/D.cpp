#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T --) {
		int n;
		cin >> n;
		LL x = max((LL)sqrt(2*n-1)-2LL,0LL);
		while ((x+1)*(x+1) <= 2*n-1) ++x;
		cout<<(x+1)/2-1<<endl;
	}
}