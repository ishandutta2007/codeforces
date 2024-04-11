#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define int long long
using namespace std;
inline int read(){
	int num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*neg;
}
int son[200010][2];
int val[200010],siz[200010];
int rnd[200010];
int n,cnt,rt;
void update(int p){
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+1;
}
int merge(int x,int y){
	if(!x) return y;
	if(!y) return x;
	if(rnd[x]<rnd[y]){
		son[x][1]=merge(son[x][1],y);
		update(x);
		return x;
	}
	else{
		son[y][0]=merge(x,son[y][0]);
		update(y);
		return y;
	}
}
void split(int now,int v,int &x,int &y){
	if(now==0){
		x=y=0;
		return ;
	}
	if(val[now]<=v)	x=now,split(son[now][1],v,son[now][1],y);
	else y=now,split(son[now][0],v,x,son[now][0]);
	update(now);
}
int new_node(int x){
	int now=++cnt;
	siz[now]=1,rnd[now]=rand(),val[now]=x;
	return now;
}
void insert(int x){
	x=-x;
	int a,b;
	split(rt,x,a,b);
	rt=merge(merge(a,new_node(x)),b);
}
void del(int x){
	x=-x;
	int a,b,c;
	split(rt,x,a,b);
	split(a,x-1,c,a);
	rt=merge(merge(c,merge(son[a][0],son[a][1])),b);
}
int findkth(int r,int p){
	while(1){
		if(r==siz[son[p][0]]+1) return val[p];
		if(r<=siz[son[p][0]]) p=son[p][0];
		else r=r-siz[son[p][0]]-1,p=son[p][1];
	}
}
int son1[200010][2];
int val1[200010],siz1[200010],sum[200010];
int rnd1[200010];
int cnt1,rt1;
void update1(int p){
	siz1[p]=siz1[son1[p][0]]+siz1[son1[p][1]]+1;
	sum[p]=sum[son1[p][0]]+sum[son1[p][1]]+val1[p];
}
int merge1(int x,int y){
	if(!x) return y;
	if(!y) return x;
	if(rnd1[x]<rnd1[y]){
		son1[x][1]=merge1(son1[x][1],y);
		update1(x);
		return x;
	}
	else{
		son1[y][0]=merge1(x,son1[y][0]);
		update1(y);
		return y;
	}
}
void split1(int now,int v,int &x,int &y){
	if(now==0){
		x=y=0;
		return ;
	}
	if(val1[now]<=v)	x=now,split1(son1[now][1],v,son1[now][1],y);
	else y=now,split1(son1[now][0],v,x,son1[now][0]);
	update1(now);
}
int new_node1(int x){
	int now=++cnt1;
	siz1[now]=1,rnd1[now]=rand(),val1[now]=sum[now]=x;
	return now;
}
void insert1(int x){
	x=-x;
	int a,b;
	split1(rt1,x,a,b);
	rt1=merge1(merge1(a,new_node1(x)),b);
}
void del1(int x){
	x=-x;
	int a,b,c;
	split1(rt1,x,a,b);
	split1(a,x-1,c,a);
	rt1=merge1(merge1(c,merge1(son1[a][0],son1[a][1])),b);
}
int findkth1(int r,int p){
	while(1){
		if(r==siz1[son1[p][0]]+1) return val1[p];
		if(r<=siz1[son1[p][0]]) p=son1[p][0];
		else r=r-siz1[son1[p][0]]-1,p=son1[p][1];
	}
}
int findsum(int r,int p){
	int s=0;
	if(!r) return 0;
	while(1){
		if(r==siz1[son1[p][0]]+1) return s+sum[son1[p][0]]+val1[p];
		if(r<=siz1[son1[p][0]]) p=son1[p][0];
		else s+=sum[son1[p][0]]+val1[p],r=r-siz1[son1[p][0]]-1,p=son1[p][1];
	}
} 
signed main(){
	srand((unsigned)time(NULL));
	n=read();
	for(int i=1;i<=n;++i){
		int t=read(),v=read();
		if(t==0){
			if(v>0) insert(v);
			else del(-v);
		}
		if(v>0) insert1(v);
		else del1(-v);
		int s=sum[rt1];
		int tot=siz1[rt1]-siz[rt];
		if(!tot) printf("%lld\n",-s);
		else if(findkth1(tot,rt1)<findkth(1,rt)){
			printf("%lld\n",-s-findsum(tot-1,rt1)-findkth(1,rt));
		}
		else printf("%lld\n",-s-findsum(tot,rt1));
	}
	return 0;
}