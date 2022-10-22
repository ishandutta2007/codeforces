#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,q;
int p[200010],pos[200010];
int L[200010],R[200010];
int stk[200010],top;
struct oper{
	int l,r;
};
struct qry{
	int l,r,id;
};
vector<oper>op[200010];
vector<qry>que[200010];
int ans[1000010];
vector<int>d[200010];
bool in[200010];
struct val{
	int k,b;
	void operator +=(const val x){
		k+=x.k,b+=x.b;
	}
};
val operator +(const val &x,const val &y){
	return val{x.k+y.k,x.b+y.b};
}
val operator *(const val &x,const int &y){
	return val{x.k*y,x.b*y};
}
struct node{
	val sum,tag;
}tre[800010];
void pushdown(int p,int l,int r){
	int mid=l+r>>1;
	tre[p<<1].sum+=tre[p].tag*(mid-l+1);
	tre[p<<1|1].sum+=tre[p].tag*(r-mid);
	tre[p<<1].tag+=tre[p].tag;
	tre[p<<1|1].tag+=tre[p].tag;
	tre[p].tag=val{0,0};
}
void pushup(int p){
	tre[p].sum=tre[p<<1].sum+tre[p<<1|1].sum;
}
void update(int p,int l,int r,int L,int R,int K,int B){
	// printf("p:%d,l:%d,r:%d,L:%d,R:%d,K:%d,B:%d\n",p,l,r,L,R,K,B);
	if(l>=L&&r<=R){
		tre[p].sum+=val{K,B}*(r-l+1);
		tre[p].tag+=val{K,B};return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,K,B);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,K,B);
	pushup(p);
}
val query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tre[p].sum;
	val res=val{0,0};
	int mid=l+r>>1;
	pushdown(p,l,r);
	if(L<=mid) res+=query(p<<1,l,mid,L,R);
	if(R>mid) res+=query(p<<1|1,mid+1,r,L,R);
	return res;
}
void del(int x,int y){
	for(oper i:op[x]){
		update(1,1,n,i.l,i.r,-1,y-1);
	}in[x]=0;
}
signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) p[i]=read(),pos[p[i]]=i;
	for(int i=1;i<=n;++i){
		for(int j=1;j*i<=n;++j) if(i!=j){
			d[i*j].pb(i);
		}
	}
	for(int i=1;i<=q;++i){
		int l=read(),r=read();
		que[r].pb(qry{l,r,i});
	}
	for(int i=1;i<=n;++i){
		// printf("i:%d\n",i);
		while(top&&p[stk[top]]<p[i]){
			del(stk[top],i);--top;
		}
		L[i]=stk[top];
		for(int j=p[i]+p[i];j<=n;j+=p[i]) if(j/p[i]!=p[i]&&in[pos[j]]){
			int t=pos[j/p[i]];
			if(t<=i){
				int l=L[pos[j]]+1,r=min(pos[j],pos[j/p[i]]);
				if(l>r) continue ;
				op[pos[j]].pb(oper{l,r});
				update(1,1,n,l,r,1,1-i);L[pos[j]]=r;
			}
		}
		for(int j:d[p[i]]) if(p[i]/j!=j&&pos[j]<=i&&pos[p[i]/j]<=i) L[i]=max(L[i],min(pos[j],pos[p[i]/j]));
		if(L[i]>stk[top]){
			update(1,1,n,stk[top]+1,L[i],1,1-i);
			op[i].pb(oper{stk[top]+1,L[i]});
		}
		in[i]=1;stk[++top]=i;
		for(qry j:que[i]){
			val res=query(1,1,n,j.l,j.r);
			ans[j.id]=res.k*i+res.b;
		}
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
}