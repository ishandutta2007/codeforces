#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int n,a[N];
int ok(int x) {
	if(x<=1 || x>=n) return 0;
	if(a[x]>a[x-1] && a[x]>a[x+1]) return 1;
	if(a[x]<a[x-1] && a[x]<a[x+1]) return 1;
	return 0;
}
int cnt;
int change(int pos,int x) {
	int tmp=cnt;
	tmp -= ok(pos); tmp -= ok(pos-1); tmp-=ok(pos+1);
	int y=a[pos];
	a[pos]=x;
	tmp += ok(pos); tmp += ok(pos-1); tmp+=ok(pos+1);
	a[pos]=y;
	return tmp;
}
int main() {
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		cnt=0;
		for(int i=2;i<n;i++){
			if(a[i]<a[i+1] && a[i]<a[i-1])cnt++;
			if(a[i]>a[i+1] && a[i]>a[i-1])cnt++;
		}

		int ans=cnt;
		for(int i=1;i<=n;i++){
			ans=min(ans,change(i,a[i+1]-1));
			ans=min(ans,change(i,a[i+1]+1));
			ans=min(ans,change(i,a[i-1]-1));
			ans=min(ans,change(i,a[i-1]+1));
			ans=min(ans,change(i,a[i-1]));
			ans=min(ans,change(i,a[i+1]));
		}
		printf("%d\n", ans);
	}
}