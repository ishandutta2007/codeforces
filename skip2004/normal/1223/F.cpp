#include<bits/stdc++.h>
typedef unsigned long long ull,u64;
const int maxn = 1001000;
ull hs[maxn],p[maxn];
struct Stack{
	int st[maxn],top;
	ull h;
	inline void clear(){ top = 0,h = 0; }
	inline void push(int x){
		if(top && x == st[top]) h ^= hs[top--] * x;
		else h ^= hs[++top] * x,st[top] = x;
	}
}a,b;
int buf[maxn]; long long ans;
inline void solve(int l,int r){
	if(l == r) return ;
	int mid = l + r >> 1;
	solve(l,mid),solve(mid+1,r);
	a.clear(),b.clear(); std::vector<ull> v1,v2;
	for(int i=mid;i>=l;--i) a.push(buf[i]),v1.push_back(a.h);
	for(int i=mid+1;i<=r;++i) b.push(buf[i]),v2.push_back(b.h);
	std::sort(v1.begin(),v1.end()); std::sort(v2.begin(),v2.end());
	l = 0,r = 0;
	for(ull i : v2){
		while(l != v1.size() && v1[l] < i) ++ l;
		while(r != v1.size() && v1[r] <= i) ++ r;
		ans += r - l;
	}
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::mt19937_64 rd(time(0));
	for(ull & i : hs) i = rd() | 7;
	int n,q;
	std::cin >> q;
	while(q--){
		std::cin >> n;
		for(int i=1;i<=n;++i) p[i] = i;
		std::shuffle(p + 1,p + n + 1,rd);
		for(int i=1;i<=n;++i) std::cin >> buf[i],buf[i] = p[buf[i]];
		solve(1,n);
		std::cout << ans << '\n',ans=0;
	}
}