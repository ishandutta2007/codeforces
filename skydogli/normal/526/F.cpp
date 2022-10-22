#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 300005
int n,k,pos[MN];
int Min[MN<<2],cnt[MN<<2],tag[MN<<2];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	Min[x]=min(Min[Ls],Min[Rs]);
	cnt[x]=(Min[Ls]==Min[x]?cnt[Ls]:0)+(Min[Rs]==Min[x]?cnt[Rs]:0);
	Min[x]+=tag[x];
}
void build(int x,int l,int r){
	if(l==r){Min[x]=1000000;cnt[x]=1;return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	pushup(x);
}
void change(int x,int l,int r,int b,int e,int v){
	if(l>e||r<b)return;
	if(b<=l&&r<=e){
		Min[x]+=v,tag[x]+=v;
//		cerr<<"change: "<<l<<" "<<r<<" "<<v<<" "<<Min[x]<<endl;
		return;
	}
	if(b<=mid)change(Ls,l,mid,b,e,v);
	if(e>mid) change(Rs,mid+1,r,b,e,v);
	pushup(x);
}
int st1[MN],st2[MN],a[MN];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		a[x]=y;
	}
	long long ans=0;
	build(1,1,n);
	int top1=0,top2=0;
	for(int i=1;i<=n;++i){
		while(top1>0&&a[st1[top1]]<a[i]){
			change(1,1,n,st1[top1-1]+1,st1[top1],a[i]-a[st1[top1]]);
			top1--;
		}
		while(top2>0&&a[st2[top2]]>a[i]){
			change(1,1,n,st2[top2-1]+1,st2[top2],a[st2[top2]]-a[i]);
			top2--;
		}
		st1[++top1]=st2[++top2]=i;
//		cerr<<"FK "<<top1<<" "<<top2<<endl;
		change(1,1,n,i,i,i-1000000);
		ans+=cnt[1];
//		cerr<<i<<": "<<Min[1]<<" "<<cnt[1]<<endl;
//		if(i==3)break;
	}
	printf("%lld\n",ans);
	return 0;
}