#include<bits/stdc++.h>
const int maxn = 500300;
typedef long long ll;
std::priority_queue<int,std::vector<int>,std::greater<int>> q;
int t,n;
int nxt[maxn];
std::vector<int> to[maxn];
int a[maxn],map[maxn],id;
int tr[maxn];
inline void dfs(int x){ for(int i:to[x]) a[i] = id --,dfs(i); }
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	for(std::cin >> t;t--;){
		std::cin >> n;
		for(int i=1;i<=n;++i){
			std::cin >> nxt[i];
			if(nxt[i] == -1) nxt[i] = i + 1;
			to[nxt[i]].push_back(i);
		}
		for(int i=1;i<=n+1;++i) tr[i] = 1e9;
		id = n;
		dfs(n + 1);
		int ok = 1;
		for(int i=n;i>=1;--i){
			int x = n+1;
			for(int j=a[i];j<=n+1;j+=j&-j) x = std::min(x,tr[j]);
			ok &= x == nxt[i];
			for(int j=a[i];j;j&=j-1) tr[j] = std::min(tr[j],i);
		}
		if(ok)
			for(int i=1;i<=n;++i) std::cout << a[i] << " \n"[i==n];
		else
			std::cout << "-1\n";
		for(int i=1;i<=n+1;++i) to[i].clear();
	}
}