#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
int a[MN],Log[1000005],vis[25];
bool chk(){
	for(int i=0;i<=20;++i)if(vis[i])return 1;
	return 0;
}
signed main(){
	int T=read();
	Log[0]=-1;for(int i=1;i<=1000000;++i)Log[i]=Log[i>>1]+1;
	while(T--){
		int n=read(),w=read();
		for(int i=0;i<=20;++i)vis[i]=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			vis[Log[a[i]]]++;
		}
		sort(a+1,a+1+n);reverse(a+1,a+1+n);
		int ti=0;
		while(chk()){
			ti++;
			int v=w;
			for(int i=20;i>=0;--i)while(v>=(1<<i)&&vis[i])vis[i]--,v-=(1<<i);
		}
		cout<<ti<<endl;
	}
	return 0;
}