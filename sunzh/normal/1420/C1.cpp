#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,q;
int a[300010];
int main(){
	T=read();
	while(T--){
		n=read(),q=read();
		for(int i=1;i<=n;++i) a[i]=read();
		long long ans=0,sum=0;
		int pos=1;
		while(pos<=n){
			int st=pos;
			while(pos<=n&&a[pos+1]<=a[pos]) ++pos;
			ans=max(ans,sum+a[st]);
			sum+=a[st]-a[pos];
			++pos;
		}
		printf("%lld\n",max(ans,sum));
	}
	return 0;
}