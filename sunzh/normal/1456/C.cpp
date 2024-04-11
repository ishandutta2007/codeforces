#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
int a[500010];
bool cmp(int x,int y){
	return x>y;
}
int b[500010];
int main(){
	n=read(),k=read();++k;
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1,cmp);
	long long sum=0,ans=0;
	int pos=0;
	for(int i=1;i<=n;++i){
		ans+=sum;sum+=a[i];
		pos=i+1;
		if(k>1&&sum<0){
			pos=i; a[i]=sum;
			break ;
		}
	}
	int cnt=0;
	for(int i=pos;i<=n;++i){
		b[++cnt]=a[i];
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;++i){
		ans+=1ll*b[i]*((i-1)/k);
	}
	printf("%lld\n",ans);
}