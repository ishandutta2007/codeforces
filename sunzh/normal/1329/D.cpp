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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
char str[200010];
int cnt[27];
int stk[200010],top;
PII ope[200010];
int sum;
PII t[200010];
int tot;
bool check(){
	int s=0,mx=0;
	for(int i=0;i<26;++i){
		s+=cnt[i];mx=max(mx,cnt[i]);
	}
	return mx*2<=s;
}
char tr[200010];
int Sum[800010],Tag[800010];
void pushup(int p,int l,int r){
	if(Tag[p]) Sum[p]=r-l+1;else Sum[p]=Sum[p<<1]+Sum[p<<1|1];
}
void build(int p,int l,int r){
	Sum[p]=Tag[p]=0;
	if(l==r) return ;
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
void update(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		Tag[p]=1;Sum[p]=r-l+1;return ;
	}
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R);
	if(R>mid) update(p<<1|1,mid+1,r,L,R);
	pushup(p,l,r);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return Sum[p];
	if(Tag[p]) return min(R,r)-max(L,l)+1;
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res+=query(p<<1,l,mid,L,R);
	if(R>mid) res+=query(p<<1|1,mid+1,r,L,R);
	return res;
}
int main(){
	T=read();
	while(T--){
		scanf("%s",str+1);tot=0;sum=0;memset(cnt,0,sizeof(cnt));
		int n=strlen(str+1);
		for(int i=2;i<=n;++i){
			if(str[i]==str[i-1]) ++cnt[str[i]-'a'],t[++tot]=mp(i,str[i]-'a');
		}
		int mx=0,pos=0;
		for(int i=0;i<26;++i) if(cnt[i]>mx) mx=cnt[i],pos=i;
		if((mx<<1)>tot){
			top=0;
			for(int i=1;i<=tot;++i){
				if(t[i].se==pos){
					if(!top||str[stk[top]]==pos+'a') stk[++top]=t[i].fi;
					else{
						ope[++sum]=mp(stk[top],t[i].fi-1);--cnt[str[stk[top]]-'a'];--cnt[t[i].se];
						--top;
					}
				}
				else{
					if(!top||str[stk[top]]!=pos+'a') stk[++top]=t[i].fi;
					else{
						ope[++sum]=mp(stk[top],t[i].fi-1);
						--top;
					}
				}
			}
		}
		else{
			top=0;
			if(tot&1) cnt[t[tot].se]--,--tot;
			for(int i=1;i<=tot;++i){
				if(!top||str[stk[top]]==str[t[i].fi]) stk[++top]=t[i].fi;
				else{
					--cnt[str[stk[top]]-'a'];--cnt[t[i].se];
					if(check()){
						ope[++sum]=mp(stk[top],t[i].fi-1);--top;
					}
					else stk[++top]=t[i].fi,++cnt[str[stk[top-1]]-'a'],++cnt[t[i].se];
				}
			}
		}
		build(1,1,n);
		for(int i=1;i<=sum;++i){
			int x=ope[i].fi-query(1,1,n,1,ope[i].fi);
			int y=ope[i].se-query(1,1,n,1,ope[i].se);
			// printf("%d %d\n",ope[i].fi,ope[i].se);
			update(1,1,n,ope[i].fi,ope[i].se);
			ope[i]=mp(x,y);
		}
		tot=0;
		for(int i=1;i<=n;++i){
			if(!query(1,1,n,i,i)){
				tr[++tot]=str[i];
			}
		}
		int lst=1;
		for(int i=1;i<tot;++i) if(tr[i]==tr[i+1]){
			ope[++sum]=mp(1,i-lst+1);lst=i+1;
		}
		ope[++sum]=mp(1,tot+1-lst);
		printf("%d\n",sum);
		for(int i=1;i<=sum;++i) printf("%d %d\n",ope[i].fi,ope[i].se);
	}
}