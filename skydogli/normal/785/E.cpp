#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
#define Ls Tree[x].ls
#define Rs Tree[x].rs
#define MN 200005
#define LL long long
int n,q,a[MN],root[MN],cnt;
namespace seg{
	struct tree{
		int sum,ls,rs;
	}Tree[MN<<7];
	void Ins(int &x,int l,int r,int loc,int v){
		if(!x)x=++cnt;
		Tree[x].sum+=v;
		if(l==r)return;
		if(loc<=mid)Ins(Ls,l,mid,loc,v);
		else Ins(Rs,mid+1,r,loc,v);
	}
	int ask(int x,int l,int r,int b,int e){
		//	cout<<"ask: "<<x<<" "<<l<<" "<<r<<" "<<b<<" "<<e<<" "<<Tree[x].sum<<endl;
		if(!x)return 0;
		if(l>e||r<b)return 0;
		if(b<=l&&r<=e){
			//		cout<<"OK!:  "<<x<<" "<<l<<" "<<r<<" "<<b<<" "<<e<<" "<<Tree[x].sum<<endl;
			return Tree[x].sum;
		}
		return ask(Ls,l,mid,b,e)+ask(Rs,mid+1,r,b,e);
	}
}
void Ins(int loc,int v,int ad){
	while(loc<=n){
		seg::Ins(root[loc],1,n,v,ad);
		loc+=(loc&(-loc));
	}
}
int ask(int l,int r,int b,int e){
	if(l>r)return 0;
	int resl=0,resr=0;
	//	cout<<"ask: "<<l<<" "<<r<<" "<<b<<" "<<e<<": ";
	l--;
	while(l){
		resl+=seg::ask(root[l],1,n,b,e);
		l-=(l&(-l));
	}
	while(r){
		resr+=seg::ask(root[r],1,n,b,e);
		r-=(r&(-r));
	}
//	cout<<" "<<resr<<" "<<resl<<endl;
	return resr-resl;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)Ins(i,i,1),a[i]=i;
	LL res=0;
	for(int i=1;i<=q;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>r)swap(l,r);
		if(l!=r){
			int Ad=ask(l+1,r-1,1,a[r])+ask(l+1,r-1,a[l],n);
			int De=ask(l+1,r-1,1,a[l])+ask(l+1,r-1,a[r],n);
			//		cout<<"? "<<Ad<<" "<<De<<endl;
			res=res+Ad-De+(a[l]>a[r]?-1:1);
			Ins(r,a[l],1);Ins(l,a[l],-1);
			Ins(l,a[r],1);Ins(r,a[r],-1);
			swap(a[l],a[r]);
		}
		printf("%I64d\n",res);
	}
	return 0;
}