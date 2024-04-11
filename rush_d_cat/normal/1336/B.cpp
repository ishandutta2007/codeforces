#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
vector<int> v1,v2,v3;
LL solve(vector<int>& v1,vector<int>& v2,vector<int>& v3){
	LL res=2e18;
	for(auto x:v1){
		auto it1=lower_bound(v2.begin(),v2.end(),x); if(it1==v2.end()) continue;
		auto it2=upper_bound(v3.begin(),v3.end(),x); if(it2==v3.begin()) continue; it2--;
		LL rig=(*it1),lef=(*it2);
		res=min(res,(rig-lef)*(rig-lef)+(x-lef)*(x-lef)+(rig-x)*(rig-x));
	}
	return res;
}
int main() {
	scanf("%d",&t);
	while(t--){
		int c1,c2,c3; scanf("%d%d%d",&c1,&c2,&c3);
		v1.clear(); v2.clear(); v3.clear();
		for(int i=1;i<=c1;i++){
			int x; scanf("%d",&x); v1.push_back(x);
		}
		for(int i=1;i<=c2;i++){
			int x; scanf("%d",&x); v2.push_back(x);
		}
		for(int i=1;i<=c3;i++){
			int x; scanf("%d",&x); v3.push_back(x);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		sort(v3.begin(),v3.end());
		LL ans=2e18;
		ans=min(ans,solve(v1,v2,v3));
		ans=min(ans,solve(v1,v3,v2));
		ans=min(ans,solve(v2,v1,v3));
		ans=min(ans,solve(v2,v3,v1));
		ans=min(ans,solve(v3,v1,v2));
		ans=min(ans,solve(v3,v2,v1));
		printf("%lld\n", ans);

	}
}