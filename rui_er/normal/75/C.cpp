// Problem: CF75C Modified GCD
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF75C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int a, b, T;
vector<int> d;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &a, &b);
	int gcd = __gcd(a, b);
	for(int i=1;1LL*i*i<=gcd;i++) {
		if(!(gcd % i)) {
			d.push_back(i);
			if(i * i < gcd) d.push_back(gcd/i);
		}
	}
	sort(d.begin(), d.end());
	for(scanf("%d", &T);T;T--) {
		int L, R;
		scanf("%d%d", &L, &R);
		auto it = --upper_bound(d.begin(), d.end(), R);
		printf("%d\n", *it<L?-1:*it);
	}
	return 0;
}