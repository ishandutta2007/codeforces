#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,t;
set<PII>st[200010];
set<PII>::iterator it;
struct op{
	int op,x,y;
}a[200010];
int sy[200010];
void update(int p,int x,int y,int op){
	PII k=mp(x,y);
	while(p){
		if(op==1) st[p].insert(k);
		else st[p].erase(k);
		p-=p&-p;
	}
}
PII query(int p,int x,int y){
	PII k=mp(x,y);
	PII res={0x7f7f7f7f,0x7f7f7f7f};
	while(p<=t){
		it=st[p].lower_bound(k);
		if(it!=st[p].end()) res=min(res,*it);
		p+=p&-p;
	}
	return res.se>=0x7f7f3f3f?mp(-1,-1):res;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		char str[20];scanf("%s",str+1);
		a[i].x=read(),a[i].y=read();sy[i]=a[i].y;
		switch(str[1]){
			case 'a':{ a[i].op=1;break;	}
			case 'f':{ a[i].op=2;break;	}
			case 'r':{ a[i].op=3;break;	}
		}
	}
	sort(sy+1,sy+n+1);
	t=unique(sy+1,sy+n+1)-sy-1;
	for(register int i=1;i<=n;++i){
		switch(a[i].op){
			case 1:{
				int p=lower_bound(sy+1,sy+t+1,a[i].y)-sy;
				update(p,a[i].x,a[i].y,1);
				break;
			}
			case 2:{
				int p=lower_bound(sy+1,sy+t+1,a[i].y+1)-sy;
				PII ans=query(p,a[i].x+1,a[i].y+1);
				if(ans.fi==-1) printf("-1\n");
				else printf("%d %d\n",ans.fi,ans.se);
				break;
			}
			case 3:{
				int p=lower_bound(sy+1,sy+t+1,a[i].y)-sy;
				update(p,a[i].x,a[i].y,-1);
				break;
			} 
		}
	}
	return 0;
}