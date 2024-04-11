#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);c=getchar();
	}
	return x;
}
int T,n,k;
int a[110];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i) a[i]=read();
		int ans=0;
		for(int i=1;i<=k;++i) if(a[i]>k) ++ans;
		printf("%d\n",ans);
	}
}