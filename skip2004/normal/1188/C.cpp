#include<bits/stdc++.h>
const int maxn = 1010;
const int mod = 998244353;
inline void reduce(int & x){ x += x >> 31 & mod; }
int n,k;
int a[maxn];
int f[maxn][maxn];
int pre[maxn][maxn];
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> k;
	for(int i=1;i<=n;++i) std::cin >> a[i];
	std::sort(a + 1,a + n + 1);
	int ans = 0;
	for(int i=0;i<=100000 / (k - 1);++i){
		for(int j=0;j<=n;++j){
			std::fill(f[j],f[j] + k + 1,0);
			std::fill(pre[j],pre[j] + k + 1,0);
		}
		**pre = 1;
		int p = 1;
		for(int j=1;j<=n;++j){
			while(p < j && a[j] - a[p] > i) ++ p;
			for(int l=0;l<=k;++l){
				if(l != 0){
					f[j][l] = pre[p - 1][l - 1];
				}
				reduce(pre[j][l] = pre[j-1][l] + f[j][l] - mod);
			}
			reduce(ans += f[j][k] - mod);
		}
	}
	std::cout << ans << '\n';
}