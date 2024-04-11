#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,m;
set<int> ans,gou;
int op[N],a[N],cnt[N];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) ans.insert(i);
	for(int i=1;i<=m;i++){
		char s[2];scanf("%s%d",s,&a[i]);
		if(s[0]=='+')op[i]=1;
		if(op[i]==1&&i>=2&&a[i]!=a[i-1]) ans.erase(a[i]);
	}
	for(int i=1;i<m;i++){
		if(op[i]==0&&a[i]!=a[i+1]) ans.erase(a[i]);
	}
	for(int i=m;i>=1;i--){
		if(op[i]==1){
			if(gou.size()>=2 || (gou.size()==1 && (*gou.begin())!=a[i]) ) {
				ans.erase(a[i]);
			}
		}
		if(op[i]==0){
			if(gou.size()>=2 || (gou.size()==1 && (*gou.begin())!=a[i]) ) {
				ans.erase(a[i]);
			}
		}
		if(op[i]==0){
			gou.insert(a[i]);
		}
		if(op[i]==1){
			gou.erase(a[i]);
		}
	}
	gou.clear();
	for(int i=1;i<=m;i++){
		if(op[i]==1){
			if(gou.size()>=2 || (gou.size()==1 && (*gou.begin())!=a[i]) ) {
				ans.erase(a[i]);
			}
		}
		if(op[i]==0){
			if(gou.size()>=2 || (gou.size()==1 && (*gou.begin())!=a[i]) ) {
				ans.erase(a[i]);
			}
		}		
		if(op[i]==1){
			gou.insert(a[i]);
		} else {
			gou.erase(a[i]);
		}
	}
	printf("%d\n", ans.size());
	for(auto x:ans){
		printf("%d ", x);
	}
}