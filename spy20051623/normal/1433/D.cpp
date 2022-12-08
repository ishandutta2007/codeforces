#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int x=-1;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]!=a[1]&&x==-1)x=i;
		}
		if(x==-1){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=2;i<=n;++i){
			if(a[i]==a[1])printf("%d %d\n",x,i);
			else printf("1 %d\n",i);
		}
	}
	return 0;
}