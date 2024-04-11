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
#define int long long
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
int p[200010];
int q;
struct node{
	int l,r,id;
	bool operator <(const node &x)const{
		return r<x.r;
	} 
}Q[200010]; 
int Ans[200010];
int mn[800010],cnt[800010],tag[800010],ans[800010],add[800010];
void pushdown(int p){
	if(add[p]){
		add[p<<1]+=add[p],add[p<<1|1]+=add[p];
		mn[p<<1]+=add[p],mn[p<<1|1]+=add[p];
		add[p]=0;
	}
	if(tag[p]){
		if(mn[p<<1]==mn[p]){
			tag[p<<1]+=tag[p];ans[p<<1]+=cnt[p<<1]*tag[p];
		}
		if(mn[p<<1|1]==mn[p]){
			tag[p<<1|1]+=tag[p];ans[p<<1|1]+=cnt[p<<1|1]*tag[p];
		}
		tag[p]=0;
	}
}
void pushup(int p){
	ans[p]=ans[p<<1]+ans[p<<1|1];mn[p]=min(mn[p<<1],mn[p<<1|1]);
	cnt[p]=(mn[p]==mn[p<<1]?cnt[p<<1]:0)+(mn[p]==mn[p<<1|1]?cnt[p<<1|1]:0);
}
void build(int p,int l,int r){
	mn[p]=l,cnt[p]=1;
	if(l==r){
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
void modify(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		mn[p]+=k,add[p]+=k;return ;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(L<=mid) modify(p<<1,l,mid,L,R,k);
	if(R>mid) modify(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return ans[p];
	int mid=l+r>>1;
	pushdown(p);pushup(p);
	int res=0;
	if(L<=mid) res+=query(p<<1,l,mid,L,R);
	if(R>mid) res+=query(p<<1|1,mid+1,r,L,R);
	return res;
}
int stk1[200010],top1;
int stk2[200010],top2;
signed main(){
	n=read();
	for(int i=1;i<=n;++i) p[i]=read();
	q=read();
	for(int i=1;i<=q;++i) Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
	sort(Q+1,Q+q+1);
	int it=1;
	build(1,1,n);
	for(int i=1;i<=n;++i){
		--add[1];mn[1]--;
		while(top1&&p[stk1[top1]]>p[i]){
			modify(1,1,n,stk1[top1-1]+1,stk1[top1],p[stk1[top1]]-p[i]);
			--top1;
		}
		stk1[++top1]=i;
		while(top2&&p[stk2[top2]]<p[i]){
			modify(1,1,n,stk2[top2-1]+1,stk2[top2],p[i]-p[stk2[top2]]);
			--top2;
		}
		stk2[++top2]=i;
		++tag[1];ans[1]+=cnt[1];
//		printf("mn[%d]=%d\n",i,mn[1]);
		while(it<=q&&Q[it].r==i){
			Ans[Q[it].id]=query(1,1,n,Q[it].l,i);
			++it;
		}
	}
	for(int i=1;i<=q;++i) printf("%lld\n",Ans[i]);
	return 0;
}