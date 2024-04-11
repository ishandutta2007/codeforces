// LUOGU_RID: 96194434
// Problem: CF582A GCD Table
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF582A
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
const int N = 505;

int n;
multiset<int, greater<int> > s;
vector<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n*n) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	rep(i, 1, n) {
		int x = *s.begin();
		s.erase(s.begin());
		for(int y : ans) {
			auto itL = s.lower_bound(__gcd(x, y)), itR = itL;
			++itR; ++itR;
			s.erase(itL, itR);
		}
		ans.push_back(x);
	}
	for(int i : ans) printf("%d ", i);
	return 0;
}