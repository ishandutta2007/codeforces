#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=102;
int t,n,m,a[N][N];
vector<int> v[N][N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) v[i][j].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				v[min(i,n+1-i)][min(j,m+1-j)].push_back(a[i][j]);
			}
		}
		LL ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sort(v[i][j].begin(),v[i][j].end());
				if(v[i][j].size()){
					int pos=(v[i][j].size()-1)/2;
					for(int x=0;x<v[i][j].size();x++){
						ans+=abs(v[i][j][pos] - v[i][j][x]);
					}
				}
			}	
		}
		printf("%lld\n", ans);
	}
}