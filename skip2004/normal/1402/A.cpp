#include<bits/stdc++.h>
const int maxn = 100100;
typedef long long ll;
int k,n,m;
int a[maxn],max[maxn];
int t[maxn],pos[maxn],b[maxn];
struct pr { int val, id; };
struct opt { ll x, y; int id; };
inline int cmp0(const pr & x,const pr & y) { return x.val > y.val; }
inline int cmp1(const opt& a,const opt& b){ return (long double) a.x / a.y > (long double) b.x / b.y; }
inline int cmp2(const opt& a,const opt& b){ return t[a.id] < t[b.id]; }
std::vector<pr> v0[maxn];
std::vector<opt> ans;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> k >> n >> m;
	for(int i = 1;i <= k;++i) std::cin >> a[i];
	for(int i = 1;i <= n;++i){
		std::cin >> t[i] >> pos[i] >> b[i];
		if(t[i] == 1){
			if(b[i] > b[max[pos[i]]])
				max[pos[i]] = i;
		} else if(t[i] == 2) {
			v0[pos[i]].push_back({b[i],i});
		} else {
			if(b[i] != 1)
				ans.push_back({b[i],1,i});
		}
	}
	for(int i = 1;i <= k;++i) {
		if(max[i]) v0[i].push_back({b[max[i]] - a[i],max[i]});
		std::sort(v0[i].begin(),v0[i].end(),cmp0);
		ll now = a[i];
		for(auto x : v0[i]) if(x.val >= 0) {
			ans.push_back({now + x.val,now,x.id}), now += x.val;
		}
	}
	int cnt = std::min<int>(ans.size(),m);
	std::nth_element(ans.begin(),ans.begin() + cnt,ans.end(),cmp1);
	std::sort(ans.begin(),ans.begin() + cnt,cmp2);
	std::cout << cnt <<'\n';
	for(int i = 0;i < cnt;++i)
		std::cout << ans[i].id << " \n"[i == cnt - 1];
}