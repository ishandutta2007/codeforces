#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int a[400010];
int dep[400010];
int tag[2000010],mx[2000010];
int L[400010],R[400010];
int stk[400010],top,ls[400010],rs[400010];
void dfs(int x){
//	printf("x:%d,ls:%d,rs:%d\n",x,ls[x],rs[x]);
	if(!x) return ;
	dep[ls[x]]=dep[x]+1;dep[rs[x]]=dep[x]+1;
	dfs(ls[x]);dfs(rs[x]);
}
void pushup(int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void pushdown(int p){
	if(tag[p]){
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
		mx[p<<1]+=tag[p],mx[p<<1|1]+=tag[p];
		tag[p]=0;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		mx[p]+=k,tag[p]+=k;return ;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mx[p];
	pushdown(p);
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res=max(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,query(p<<1|1,mid+1,r,L,R));
	return res;
}
void build(int p,int l,int r){
	if(l==r){
//		printf("p:%d,l:%d,dep:%d\n",p,l,dep[l]);
		mx[p]=dep[l];return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p); 
}
int mn[400010][22];
void build(){
	for(int i=1;i<=n;++i){
		while(top&&a[stk[top]]>a[i]){
			ls[i]=stk[top];--top;
		}
		if(top) rs[stk[top]]=i;stk[++top]=i;
	}
	dep[stk[1]]=1;
	dfs(stk[1]);
	build(1,1,n+n);
	
	for(int i=1;i<=n+n;++i) mn[i][0]=a[i];
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n+n;++i){
//			printf("i:%d,j:%d\n",i,j);
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		}
	}
}
int ans[200010];
int logt[400010];
int qry(int l,int r){
	int k=logt[r-l+1];
//	printf("l:%d,r:%d,k:%d,%d %d,%d %d\n",l,r,k,l,mn[l][k],r-(1<<k)+1,mn[r-(1<<k)+1][k]);
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int findr(int x){
//	printf("%d\n",qry(1,4));
	int l=x+1,r=x+n-1,res=r+1;
	while(l<=r){
		int mid=l+r>>1;
		if(qry(x,mid)<mn[x][0]){
			res=mid,r=mid-1;
		}
		else l=mid+1;
	} 
	return res;
}
int findl(int x){
	int l=x-n+1,r=x-1,res=l-1;
	while(l<=r){
		int mid=l+r>>1;
		if(qry(mid,x)<mn[x][0]){
			res=mid,l=mid+1;
		} 
		else r=mid-1;
	}
	return res;
}
int main(){
	n=read();
	for(int i=2;i<=n+n;++i) logt[i]=logt[i>>1]+1;
	for(int i=1;i<=n;++i) a[i]=a[i+n]=read();
	build();
	ans[0]=query(1,1,n+n,1,n);
	int mn=ans[0];
	for(int i=1;i<n;++i){
		int p=findr(i);
//		printf("i:%d,p:%d\n",i,p);
		update(1,1,n+n,i,p-1,-1);
		p=findl(i+n);
//		printf("l:%d\n",p);
		update(1,1,n+n,i+n,i+n,query(1,1,n+n,p,p));
		update(1,1,n+n,p+1,i+n,1);
		ans[i]=query(1,1,n+n,i+1,i+n);
		mn=min(mn,ans[i]);
//		printf("ans[%d]=%d\n",i,ans[i]);
	}
	for(int i=0;i<n;++i){
		if(ans[i]==mn){
			printf("%d %d\n",mn,i);break ;
		}
	}
}