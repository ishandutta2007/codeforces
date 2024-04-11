#include <bits/stdc++.h>
using namespace std;

int a[300005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int maxm=0,ok=0;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		if(n==1){
			printf("1\n");
			continue;
		}
		for(int i=1;i<n;++i)a[i]>a[maxm]?maxm=i:0,a[i]!=a[i-1]?ok=1:0;
		if(!maxm)while(maxm<n-1&&a[maxm]==a[maxm+1])++maxm;
		printf("%d\n",ok?maxm+1:-1);
	}
	return 0;
}