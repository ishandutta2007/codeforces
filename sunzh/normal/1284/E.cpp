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
#define int long long
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
	int x,y;
}a[2510],v[5010];
int xiangxian(node x){
	if(x.x>=0){
		if(x.y>=0) return 1;
		else return 4;
	}
	else{
		if(x.y>=0) return 2;
		else return 3;
	}
}
int cross(node x,node y){
	return x.x*y.y-y.x*x.y;
}
bool cmp(node x,node y){
	int x1=xiangxian(x);
	int x2=xiangxian(y);
	if(x1!=x2) return x1<x2;
	else return cross(x,y)>0;
}
int ans;
int C(int x,int y){
	if(x<0) return 0;
	int res=1;
	for(int i=1;i<=y;++i) res*=(x-i+1);
	for(int i=1;i<=y;++i) res/=i;
//	printf("%d %d %d\n",x,y,res);
	return res;
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(j==i) continue ;
			v[++cnt].x=a[j].x-a[i].x;
			v[cnt].y=a[j].y-a[i].y;
//			printf("j:%d,x:%d,y:%d\n",j,v[cnt].x,v[cnt].y);
		}
//		printf("cnt:%d\n",cnt);
		sort(v+1,v+cnt+1,cmp);
//		for(int j=1;j<=cnt;++j) printf("%d %d\n",v[j].x,v[j].y);
		for(int j=1;j<=cnt;++j) v[j+cnt]=v[j];
		int lst=1;
		for(int j=cnt+1;j<=2*cnt;++j){
			while(lst+cnt<j||cross(v[j],v[lst+1])>=0){
				++lst;if(lst+1==j) break ;//printf("lst:%d\n",lst);
			}
			ans+=C(j-lst-1,3);
//			printf("lst:%d,j:%d\n",lst,j);
		}
	}
//	printf("%d\n",C(n,5));
	print(5*C(n,5)-ans);
}