#include<bits/stdc++.h>
typedef double db;
const int maxn = 1010;
db f[maxn],e[maxn];
inline db calc(int id){ return (f[id] + 1) / (1 - e[id]); }
int p[maxn][maxn],vis[maxn],n;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) std::cin >> p[i][j];
	for(int i = 1;i < n;++i) f[i] = 0,e[i] = 1;
	f[n] = -1;
	for(int i = 1;i <= n;++i)
	{
		int pos = -1;
		for(int j = 1;j <= n;++j) if(!vis[j] && (pos == -1 || calc(j) < calc(pos))) pos = j;
		vis[pos] = 1;
		for(int j = 1;j <= n;++j) if(!vis[j]) {
			f[j] += e[j] * calc(pos) * p[j][pos] / 100;
			e[j] *= 1 - p[j][pos] / 100.;
		}
	}
	std::cout << std::setprecision(10) << calc(1) << '\n';
}