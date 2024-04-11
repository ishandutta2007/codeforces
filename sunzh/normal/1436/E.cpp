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
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[100010];
bool ok[100010];
struct BIT{
	int tre[100010];
	void clear(){
		memset(tre,0x3f,sizeof(tre));
	}
	void update(int x,int k){
		while(x<=n){
			tre[x]=min(tre[x],k);
			x+=x&-x;
		}
	}
	int query(int x){
		if(!x) return -1;
		int res=0x3f3f3f3f;
		while(x){
			res=min(res,tre[x]);
			x^=x&-x;
		}
		return res;
	}
}T;
int lst[100010],pre[100010];
int maxn;
bool f=1;
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		pre[i]=lst[a[i]];lst[a[i]]=i;f&=a[i]==1;
	}
	if(!f) ok[1]=1;
	T.clear();
	T.update(1,lst[1]);
	for(int i=2;i<=n+1;++i){
		int t=T.query(i-1);
		if(t>lst[i]) ok[i]=1;
		T.update(i,lst[i]);
	}
	for(int i=n;i>=1;--i){
		if(T.query(a[i]-1)>pre[i]) ok[a[i]]=1;
		T.update(a[i],pre[i]);
	}
	int t=1;
	while(ok[t]) ++t;
	printf("%d\n",t);
}