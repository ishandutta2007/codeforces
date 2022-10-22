#include<bits/stdc++.h>
const int maxn = 300300;
int p[maxn],fr[maxn];
int n;
#define emplace emplace_back
std::vector<std::pair<int,int>>v;
inline void t_s(int i,int j){
	if(i == j)return ;
	if(i > j)std::swap(i,j);
	if(2 * (j-i) >= n)
		v.emplace_back(i,j);
	else {
		if(j <= n / 2){
			v.emplace_back(j,n);
			v.emplace_back(i,n);
			v.emplace_back(j,n);
		}else{
			if(i > n/2){
				v.emplace(i,1);
				v.emplace(j,1);
				v.emplace(i,1);
			}else{
				v.emplace(i,n);
				v.emplace(j,1);
				v.emplace(1,n);
				v.emplace(i,n);
				v.emplace(j,1);
			}
		}
	}
	std::swap(fr[p[i]],fr[p[j]]);
	std::swap(p[i],p[j]);
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	for(int i=1;i<=n;++i)std::cin >> p[i],fr[p[i]]=i;;
	for(int i=1;i<=n;++i) t_s(i,fr[i]);
	std::cout << v.size() << '\n';
	for(auto i:v)
		std::cout << i.first << ' ' << i.second << '\n';
}