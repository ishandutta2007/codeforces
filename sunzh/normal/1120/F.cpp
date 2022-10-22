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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int c,d;
long long ans;
int t[100010];
char tp[100010];
int main(){
	n=read();
	c=read(),d=read();
	for(int i=1;i<=n;++i){
		t[i]=read();
		char c=getchar();
		while(c!='P'&&c!='W') c=getchar();
		tp[i]=c;
	}
	t[n+1]=read();tp[n+1]='A';
	ans=1ll*d*n;
	long long sum=0;
	int last=t[n+1];
	for(int i=n;i>=1;--i){
		ans=min(ans,1ll*c*(t[n+1]-t[i])+sum+1ll*d*(i-1));
		if(tp[i-1]==tp[i]){
			sum+=min(d,c*(last-t[i]));
		}
		else{
			last=t[i];
		}
	}
	printf("%lld\n",ans);
}