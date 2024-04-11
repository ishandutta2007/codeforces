#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N=500500;
int p[N];

int getp(int x) {
	return x == p[x] ? x : p[x] = getp(p[x]);
}

void un(int a,int b) {
	p[getp(a)] = b;
}

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int m, n; 
	 cin >> m >> n;
	 vector<int>a(m),b(n);
	 for(auto&x:a)cin >> x;
	 for(auto&x:b)cin >> x;
	 iota(p,p+m+n, 0);
	 vector<array<int,3>>arr;
	 vector<vector<int>>kek(m);
	 vector<int>all;
	 for(int i=0;i<m;++i) {
		 int s; 
		 cin >> s;
		 kek[i].resize(s);
		 for(auto&x:kek[i]) {
			 cin >> x;
			 --x;
			 arr.push_back({a[i]+b[x], i, m + x});
		 }
	 }
	 sort(arr.rbegin(),arr.rend());
	 nagai ans=0;
	 for(auto kek:arr) {
		 if (getp(kek[1]) == getp(kek[2]))
			 ans += kek[0];
		 else 
			 un(kek[1], kek[2]);
	 }
	 cout << ans << '\n';
	 return 0;
}