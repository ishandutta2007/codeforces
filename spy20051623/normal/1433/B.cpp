#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		int l=0,r=n-1;
		while(!a[l])++l;
		while(!a[r])--r;
		int cnt=0;
		for(int i=l;i<=r;++i)if(!a[i])++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}