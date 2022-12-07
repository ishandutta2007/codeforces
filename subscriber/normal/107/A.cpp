#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int n,m,x,y,z,h[11111],g[11111],gg[11111];
vector<pair<int,pair<int,int> > > ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y >> z;
		h[y]=1;
		g[x]=y;
		gg[x]=z;
	}
	for (int i=1;i<=n;i++)if (h[i]==0){
		int r=1000000000;
		x=i;
		while (g[x]){
			r=min(r,gg[x]);
			x=g[x];
		}
		if (x==i)continue;
		ans.push_back(make_pair(i,make_pair(x,r)));
	}
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++)cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	return 0;
}