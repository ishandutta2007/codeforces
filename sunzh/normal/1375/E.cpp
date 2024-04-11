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
int n;
int pos[1010];
int m;
PII ans[1000010];
int a[1010];
struct node{
	int id,x;
}b[1010];
bool cmp(node x,node y){
	return x.x==y.x?x.id<y.id:x.x<y.x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i].x=a[i],b[i].id=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;++i) a[b[i].id]=i;
	for(int i=1;i<=n;++i) pos[a[i]]=i;
	for(int i=n;i>=1;--i){
		for(int j=a[i]+1;j<=i;++j){
			int p1=pos[j];
			int p2=i;
			pos[a[i]]=p1,pos[j]=i;swap(a[i],a[p1]);
			ans[++m]=mp(p1,p2);
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=m;++i) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}