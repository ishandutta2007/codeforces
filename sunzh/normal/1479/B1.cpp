#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
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
int a[100010];
int stk[100010];
int top;
int lst[100010];
struct tree{
	int mn[400010],mxn[400010];
	void pushup(int p){
		mn[p]=min(mn[p<<1],mn[p<<1|1]);
		mxn[p]=max(mxn[p<<1],mxn[p<<1|1]);
	}
	void build(int p,int l,int r,int b){
		if(l==r){
			if(b) mn[p]=mxn[p]=a[l*2-1];
			else mn[p]=mxn[p]=a[l*2];
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid,b);build(p<<1|1,mid+1,r,b);pushup(p);
	}
	int qmin(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R) return mn[p];
		int mid=l+r>>1;
		int res=0x3f3f3f3f;
		if(L<=mid) res=min(res,qmin(p<<1,l,mid,L,R));
		if(R>mid) res=min(res,qmin(p<<1|1,mid+1,r,L,R));
		return res;
	}
	int qmax(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R) return mxn[p];
		int mid=l+r>>1;
		int res=0;
		if(L<=mid) res=max(res,qmax(p<<1,l,mid,L,R));
		if(R>mid) res=max(res,qmax(p<<1|1,mid+1,r,L,R));
		return res;
	}
}T1,T2;
int main(){
	n=read();
	if(n==1){
		printf("1\n");return 0;
	}
	for(int i=1;i<=n;++i) a[i]=read();
	T1.build(1,1,(n+1>>1),1);T2.build(1,1,n>>1,0);
	int l1,l2,ans;l1=l2=ans=0;
	for(int i=1;i<=n;++i){
		int p=i;
		while(p<n&&a[p+1]==a[i]) ++p;
		int sz=p-i+1;
		if(sz==1){
			++ans;
		}
		else{
			int ls=lst[a[i]];
			if((i&1)==(ls&1)&&(ls!=0)){
				if(i&1){
					if(T1.qmin(1,1,n+1>>1,(ls+1>>1),(i+1>>1))==a[i]&&T1.qmax(1,1,n+1>>1,ls+1>>1,i+1>>1)==a[i]){
						++ans;
					}
					else ans+=2;
				}
				else{
					if(T2.qmin(1,1,n>>1,ls>>1,i>>1)==a[i]&&T2.qmax(1,1,n>>1,ls>>1,i>>1)==a[i]){
						++ans;
					}
					else ans+=2;
				}
			}
			else ans+=2;
			
			lst[a[i]]=p;
		}
		i=p;
	}
	printf("%d\n",ans);
}