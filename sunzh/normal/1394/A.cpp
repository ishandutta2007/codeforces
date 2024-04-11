#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1ll)+(x<<3ll)+(c^48);c=getchar();}
	return x*f;
}
int ans;
int n,d,m;
int a[100010];
int s[100010],s2[100010];
int tot,tot2;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	n=read(),d=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		if(a[i]>m) s2[++tot2]=a[i];
		else s[++tot]=a[i];
	}
	sort(s+1,s+tot+1);
	sort(s2+1,s2+tot2+1,cmp);
	for(int i=1;i<=tot;++i) s[i]+=s[i-1];
	for(int i=1;i<=tot2;++i) s2[i]+=s2[i-1];
	ans=s[tot];
	for(int i=1;i<=tot2;++i){
		int emp=(i-1)*d;
		if(emp+i>n) break ;
		ans=max(ans,s2[i]+s[tot]-s[max(emp-(tot2-i),0ll)]);
	}
	printf("%lld\n",ans);
	return 0;
}