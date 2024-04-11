#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
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
int a[400010];
int b[400010],cnt[400010];
vector<PII>vec;
map<PII,int>ans;
struct c{
	int x,cnt;
	bool operator <(c d){
		return cnt<d.cnt; 
	}
}r[400010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=b[i]=read();
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;++cnt[a[i]];
//		printf("a:%d\n",a[i]);
	}
	for(int i=1;i<=m;++i) r[i].x=b[i],r[i].cnt=cnt[i];
	sort(r+1,r+m+1);
	int maxn=0,maxnl=0;
	for(int i=1;i<=n;++i){
		int S=0;
		for(int j=1;j<=m;++j) S+=min(i,cnt[j]);
//		printf("i:%d,S:%d\n",i,S);
		if((S/i)<i) break ;
		S=(S/i)*i;
		if(S>maxn) maxn=S,maxnl=i;
//		printf("i:%d,S:%d\n",i,S);
	}
	int ps=0,mr=maxn/maxnl;
	sort(b+1,b+m+1);
	int tmp=0;
	for(int i=0,x=0,y=0;i<maxnl*mr;++i){
		while(r[m].cnt==0) --m;
		r[m].cnt=min(r[m].cnt,min(maxnl,mr));
		--r[m].cnt;
		ans[mp(x,y)]=r[m].x;
		if(y==maxnl-1) x=++tmp,y=0;
		else 
		{
			++x%=mr,++y;
		}
	}
	printf("%d\n%d %d\n",maxnl*mr,mr,maxnl);
	for(int i=0;i<mr;++i){
		for(int j=0;j<maxnl;++j) printf("%d ",ans[mp(i,j)]);
		printf("\n");
	}
	return 0;
}