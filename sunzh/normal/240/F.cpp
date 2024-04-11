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
int n,m;
char s[100010];
struct node{
	int sum[27];
	int tag;
	void clear(){
		memset(sum,0,sizeof(sum));tag=-1;
	}
}seg[400010];
node operator +(const node &x,const node &y){
	node res;res.clear();
	for(int i=0;i<26;++i) res.sum[i]=x.sum[i]+y.sum[i];
	res.tag=-1;
	return res;
}
void pushup(int p){
	seg[p]=seg[p<<1]+seg[p<<1|1];
}

void pushdown(int p,int l,int r){
	if(seg[p].tag!=-1){
		int tag=seg[p].tag;
		int mid=l+r>>1;
		for(int j=0;j<26;++j) seg[p<<1].sum[j]=seg[p<<1|1].sum[j]=0;
		seg[p<<1].sum[tag]=mid-l+1;
		seg[p<<1|1].sum[tag]=r-mid;
		seg[p<<1].tag=tag;
		seg[p<<1|1].tag=tag;
		seg[p].tag=-1;
	}
}

void update(int p,int l,int r,int L,int R,int k){
	if(L>R) return ;
	if(l>=L&&r<=R){
		for(int j=0;j<26;++j) seg[p].sum[j]=0;
		seg[p].sum[k]=r-l+1;
		seg[p].tag=k;
		return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
} 

void build(int p,int l,int r){
	seg[p].clear();
	if(l==r){
		seg[p].sum[s[l]-'a']=1;
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}

node query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return seg[p];
	}
	int mid=l+r>>1;
	pushdown(p,l,r);pushup(p);
	node res;res.clear();
	if(L<=mid) res=res+query(p<<1,l,mid,L,R);
	if(R>mid) res=res+query(p<<1|1,mid+1,r,L,R);
	return res;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	build(1,1,n);
	while(m--){
		int l=read(),r=read();
		node tmp=query(1,1,n,l,r);
		bool fl=(r-l+1)&1;
		int cnt=0;
		for(int i=0;i<26;++i) if(tmp.sum[i]&1) ++cnt;
		if(cnt-fl>0) continue ;
		else{
			int pos=l,mid=(l+r)>>1,rp=r; 
			if(cnt){
				for(int i=0;i<26;++i) if(tmp.sum[i]&1){
					tmp.sum[i]--;update(1,1,n,mid,mid,i);
				}
			}
			for(int i=0;i<26;++i){
				update(1,1,n,pos,pos+(tmp.sum[i]>>1)-1,i);
				update(1,1,n,rp-(tmp.sum[i]>>1)+1,rp,i);
				pos+=(tmp.sum[i]>>1);
				rp-=(tmp.sum[i]>>1);
			}
		}
	}
	for(int i=1;i<=n;++i){
		node p=query(1,1,n,i,i);
		for(int j=0;j<26;++j) if(p.sum[j]) putchar(j+'a');
	}
}