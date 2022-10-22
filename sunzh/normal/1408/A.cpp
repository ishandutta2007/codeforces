#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[110],b[110],c[110];
int ans[110];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) b[i]=read();
		for(int i=1;i<=n;++i) c[i]=read();
		ans[1]=a[1]; 
		for(int i=2;i<n;++i){
			if(a[i]==ans[i-1]) ans[i]=b[i];
			else ans[i]=a[i];
		}
		if(a[n]==ans[n-1]||a[n]==ans[1]){
			if((b[n]==ans[n-1]||b[n]==ans[1])) ans[n]=c[n];
			else ans[n]=b[n];
		}
		else ans[n]=a[n];
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	}
}