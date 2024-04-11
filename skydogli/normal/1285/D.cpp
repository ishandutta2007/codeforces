#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MN 100005
int n,a[MN],cnt,nex[MN<<5|1][2],ans[MN],X[MN];
int main(){
	scanf("%d",&n);
	cnt=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int add=1;
		for(int j=30;j>=0;--j){
			bool op=(a[i]>>j)&1;
			if(!nex[add][op])nex[add][op]=++cnt;
			add=nex[add][op];
		}
	}
	int p=1;
	for(int i=1;i<=n;++i){
		int now=1;
		for(int j=30;j>=0;--j){
			int op=(a[i]>>j)&1;
			if(!nex[now][!op]){X[i]|=(((LL)op)<<j);}
			else X[i]|=(((LL)!op)<<j),ans[i]|=(1<<j);
			now=nex[now][op];
		}
		if(ans[i]<ans[p])p=i;
	}
	printf("%d\n",ans[p]);

	return 0;
}