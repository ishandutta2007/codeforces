#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int n,c[N],a[N],h[N];
ll ans;

inline int cmp(int x,int y){
	return a[x] < a[y];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++) scanf("%d%d",&a[i],&c[i]);
	for(int i=1;i <= n;i++) h[i] = i;
	sort(h+1,h+1+n,cmp);
	int x = 2,maxn = a[h[1]]+c[h[1]];
	while(x <= n){
		while(x <= n && maxn >= a[h[x]]) maxn = max(maxn,a[h[x]]+c[h[x]]) , x++;
		if(x <= n) ans += a[h[x]]-maxn , maxn = a[h[x]]+c[h[x]] , x++;
	}
	for(int i=1;i <= n;i++) ans += c[i];
	printf("%lld\n",ans);
	return 0;
}