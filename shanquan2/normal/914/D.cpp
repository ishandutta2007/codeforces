#include<bits/stdc++.h>
using namespace std;

int n,a[500005],tr[2000005],q;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void build(int i,int l,int r){
	if(r==l+1){
		scanf("%d",&tr[i]);
		return;
	}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid,r);
	tr[i]=gcd(tr[i<<1],tr[i<<1|1]);
}
void change(int i,int l,int r,int x,int y){
	if(r-l==1){
		tr[i]=y;
		return;
	}
	int mid=l+r>>1;
	if(x<mid)change(i<<1,l,mid,x,y);
	else change(i<<1|1,mid,r,x,y);
	tr[i]=gcd(tr[i<<1],tr[i<<1|1]);
}
int query(int i,int l,int r,int x){
	if(r==l+1)return tr[i]%x!=0;
	if(tr[i]%x==0)return 0;
	if(tr[i<<1]%x!=0&&tr[i<<1|1]%x!=0)return 2;
	int mid=l+r>>1,ans=0;
	ans+=query(i<<1,l,mid,x);
	ans+=query(i<<1|1,mid,r,x);
	return ans;
}
int check(int i,int l,int r,int a,int b,int x){
	if(a<=l&&r<=b)return query(i,l,r,x);
	int ans=0,mid=l+r>>1;
	if(a<mid)ans+=check(i<<1,l,mid,a,b,x);
	if(b>mid)ans+=check(i<<1|1,mid,r,a,b,x);
	return ans;
}
int main(){
	scanf("%d",&n);
	build(1,0,n);
	int q;scanf("%d",&q);
	while(q--){
		int c;scanf("%d",&c);
		if(c==1){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			if(check(1,0,n,l-1,r,x)<=1)printf("YES\n");else printf("NO\n");
		}else{
			int i,y;scanf("%d%d",&i,&y);
			change(1,0,n,i-1,y);
		}
	}
	return 0;
}