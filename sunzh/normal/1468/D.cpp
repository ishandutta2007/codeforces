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
int T;
int n,m,a,b;
int s[200010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read(),a=read(),b=read();
		for(int i=1;i<=m;++i) s[i]=read();
		sort(s+1,s+m+1);
		if(a>b){
			a=n-a+1,b=n-b+1;
		}
		int ans=0,pos=m;
		for(int i=1;i<b-a;++i){
			while(pos>=1&&s[pos]>b-i-1) --pos;
			if(pos) ++ans,--pos;
			else break ;
		}
		printf("%d\n",ans);
	}
}