#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int n,r,x[N],y[N],t[N],f[N];

inline int abss(int x){
	return x > 0 ? x : -x;
}

int main()
{
	scanf("%d%d",&r,&n);
	for(int i=1;i <= n;i++) scanf("%d%d%d",&t[i],&x[i],&y[i]);
	memset(f,-1,sizeof(f));
	int ans=0;
	f[0] = 0;x[0] = y[0] = 1;
	for(int i=1;i <= n;i++)
		for(int j=i-1;j >= max(0,i-2000);j--)
			if(f[j] != -1 && abss(x[i]-x[j])+abss(y[i]-y[j]) <= t[i]-t[j])
				f[i] = max(f[i],f[j]+1) , ans = max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}