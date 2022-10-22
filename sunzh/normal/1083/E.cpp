#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define int long long
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
struct node{
	int x,y,w;
	bool operator <(const node &cp)const{
		return y>cp.y;
	}
}s[1000010];
int stk[1000010];
int f[1000010];
int getX(int x){
	return s[x].x;
}
int getY(int x){
	return f[x];
}
const double eps=1e-12;
long double getslope(int x,int y){
	return (fabs(getX(x)-getX(y))<eps?1e10:(getY(y)-getY(x))/(getX(y)-getX(x)));
}
int ans;
int head,tail;
signed main(){
	n=read();
	for(int i=1;i<=n;++i) s[i].x=read(),s[i].y=read(),s[i].w=read();
	sort(s+1,s+n+1);
	head=1,tail=0;
	for(int i=1;i<=n;++i){
		while(head<tail&&getslope(stk[head],stk[head+1])>=s[i].y) ++head;
		f[i]=s[i].x*s[i].y-s[i].w;
		if(head<=tail){
			f[i]=max(f[i],getY(stk[head])-s[i].y*getX(stk[head])+s[i].x*s[i].y-s[i].w);
		}
		ans=max(ans,f[i]);
		while(head<tail&&getslope(stk[tail-1],stk[tail])<=getslope(stk[tail],i)) --tail;
		stk[++tail]=i;
	}
	print(ans);
}