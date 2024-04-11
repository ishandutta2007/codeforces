#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,a[1002],ans[10002];
int p[11]={2,3,5,7,11,13,17,19,23,29,31};
vector<int> v;
int id(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int c[11]={0}; v.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<11;j++){
				if(a[i]%p[j]==0){
					ans[i]=j; v.push_back(j);
					break;
				}
			}
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		printf("%d\n", v.size());
		for(int i=1;i<=n;i++){
			printf("%d ", id(ans[i]));
		}
		printf("\n");
	}
}