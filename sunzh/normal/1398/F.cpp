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
int dis[2][1000010];
char s[1000010];
set <int> p[2][1000010];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;--i){
		if(s[i]!='1') dis[1][i]=dis[1][i+1]+1;
		if(s[i]!='0') dis[0][i]=dis[0][i+1]+1;
	}
	for(int dig=0;dig<=1;++dig){
		int l=1,r=1;
		while(l<=n){
			while(l<=n&&s[l]=='0'+(dig^1)) ++l;
//			printf("dig:%d,l:%d\n",dig,l);
			r=l+1;
			while(r<=n&&s[r]!='0'+(dig^1)) ++r;
			int len=r-l;
			for(int i=len;i;--i)  p[dig][i].insert(l);
			l=r;
		}
	}
	for(int x=1;x<=n;++x){
		int ans=0;
		int pos=1;
		while(pos<=n){
//			printf("x:%d,pos:%d\n",x,pos);
			if(dis[0][pos]>=x||dis[1][pos]>=x){
				++ans;pos+=x;
			}
			else {
				auto it0=p[0][x].upper_bound(pos),it1=p[1][x].upper_bound(pos);
				if(it0==p[0][x].end()){
					if(it1==p[1][x].end()) pos=n+1;
					else pos=*it1;
				}
				else{
					if(it1==p[1][x].end()) pos=*it0;
					else pos=min(*it0,*it1);
				}
			}
		}
		printf("%d ",ans);
	} 
	return 0;
}