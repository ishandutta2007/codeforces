#include<bits/stdc++.h>
const int maxn = 300300;
typedef long long ll;
ll ans;
int n,m;
int a[maxn],b[maxn];
std::set<int> s;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> m;
	int mx = 0,mx2 = 0;
	for(int i=1;i<=n;++i){
		std::cin >> a[i];
		s.insert(a[i]);
		if(a[i] > mx) mx2 = mx,mx = a[i];
		else if(a[i] > mx2) mx2 = a[i];
		ans += ll(a[i]) * m;
	}
	int e = 1,e2 = 1;
	for(int i=1;i<=m;++i){
		std::cin >> b[i];
		e &= b[i] >= mx;
		e2 &= b[i] > mx;
		auto it = s.upper_bound(b[i]);
		if(it == s.begin()) {
			puts("-1");
			return 0;
		}
		ans += b[i] - *--it;
	}
	std::cout << (e ? ans + (e2 ? mx - mx2 :0) : -1) << '\n';
}