#include<bits/stdc++.h>
const int maxn = 300300;
int n,a[maxn],rk[maxn];
std::set<int> s;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	for(int i=1;i<=n;++i) std::cin >> a[i],rk[i] = i;
	std::sort(rk + 1,rk + n + 1,[](int x,int y){return a[x] < a[y];});
	int ans = 1e9;
	int l = n+1,r = 0;
	for(int i=n;i>=1;--i){
		int id = rk[i];
		if(id > l) ans = std::min(ans,a[id] / (id - l));
		if(id < r) ans = std::min(ans,a[id] / (r - id));
		l = std::min(l,id);
		r = std::max(r,id);
	}
	std::cout << ans << '\n';
}