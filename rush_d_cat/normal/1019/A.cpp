// 21:35
#include <bits/stdc++.h>
using namespace std;
const int N = 3002;
int n,m,p[N],c[N];
vector<int> vec[N];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i],&c[i]);
		vec[p[i]].push_back(c[i]);
	}
	for(int i=1;i<=m;i++)sort(vec[i].begin(),vec[i].end());
	long long ans=1e18;
	for(int x=vec[1].size();x<=n;x++) {
		int need=x-(int)vec[1].size(), sup=0; long long cost=0;
		vector<int> tmp;
		for(int i=2;i<=m;i++){
			if(vec[i].size()>=x){
				for(int j=0;j<vec[i].size();j++){
					if(j<=vec[i].size()-x){
						sup ++; cost+=vec[i][j];
					}else{
						tmp.push_back(vec[i][j]);
					}
				}
			} else {
				for(int j=0;j<vec[i].size();j++)tmp.push_back(vec[i][j]);
			}
		}
		if(sup<=need) {
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<need-sup;i++)cost+=tmp[i];
			//printf("x=%d %lld\n", x,cost);
			ans=min(ans,cost);
		}
	}
	cout<<ans<<endl;
}