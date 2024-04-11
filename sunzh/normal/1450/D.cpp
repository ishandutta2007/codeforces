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
int n;
int a[300010];
bool vis[300010];
int q[300010];
int head,tail;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),vis[i]=0;
		bool f=1;
		for(int i=1;i<=n;++i) if(vis[a[i]]) f=0;else vis[a[i]]=1;
		int l=2,r=n,res=n+1;
		auto chk=[&](int x){
			for(int i=1;i<=n;++i) vis[i]=0;
			head=1,tail=0;
			for(int i=1;i<x;++i){
				while(head<=tail&&a[q[tail]]>a[i]) --tail;
				
				q[++tail]=i;
			}
			for(int i=x;i<=n;++i){
				while(head<=tail&&i-q[head]>=x) ++head;
				while(head<=tail&&a[q[tail]]>a[i]) --tail;
				q[++tail]=i;
				if(vis[a[q[head]]]) return false;
				vis[a[q[head]]]=1;
			}
			for(int i=1;i<=n-x+1;++i) if(!vis[i]) return false;
			return true ;
		};
		while(l<=r){
			int mid=l+r>>1;
			if(chk(mid)) r=mid-1,res=mid;
			else l=mid+1;
		}
		putchar('0'+f);
		for(int i=2;i<=n;++i) if(i<res) putchar('0');else putchar('1');
		putchar('\n');
	}
}