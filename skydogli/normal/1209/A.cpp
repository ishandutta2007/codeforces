#include<bits/stdc++.h>
using namespace std;
int p[14]={2,3,5,7,11,13,17,19,23,29,31,37,41,47};
int n,a[105],num[105],vis[105],cnt,sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int ans=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		if(a[i]!=-1){
			++ans;
			for(int j=i+1;j<=n;++j)
				if(a[j]%a[i]==0)a[j]=-1;
		}
	printf("%d",ans);
	return 0;
}