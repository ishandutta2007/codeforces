#include <bits/stdc++.h>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=10000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n,c;
int p[Maxn+5],s[Maxn+5];
ll f[2][Maxn+5];
int main(){
	read(n),read(c);
	for(int i=1;i<=n;i++){
		read(p[i]);
	}
	for(int i=1;i<=n;i++){
		read(s[i]);
	}
	for(int i=1;i<=n;i++){
		int now=(i&1),pre=now^1;
		memset(f[now],0x3f,sizeof f[now]);
		f[now][0]=f[pre][0]+p[i];
		for(int j=1;j<=i;j++){
			f[now][j]=min(f[pre][j]+p[i]+1ll*c*j,f[pre][j-1]+s[i]);
		}
	}
	ll ans=Inf;
	for(int i=0;i<=n;i++){
		ans=min(ans,f[n&1][i]);
	}
	printf("%lld\n",ans);
	return 0;
}