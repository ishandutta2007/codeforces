#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int T,n,p[N],vis[N],c[N];
vector<int> dv[N];
bool ok[N];
int chk(vector<int> &v) {
	int sz=v.size();
	for(auto d: dv[sz]) {
		for(int i=0;i<d;i++){
			bool fg=1;
			for(int j=i;j<sz;j+=d){
				if(v[j]!=v[i]){
					fg=0;
					break;
				}
			}
			if(fg){
				return d;
			}
		}
	}
}

int main() {
	for(int i=1;i<N;i++)for(int j=i;j<N;j+=i)dv[j].push_back(i);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);vis[i]=0;
		}
		int ans=1e9;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				int now=i;
				vector<int> v;
				while(vis[now]==0){
					vis[now]=1; now=p[now]; v.push_back(c[now]);
				}
				ans=min(ans,chk(v));
			}
		}
		printf("%d\n", ans);
	}
}