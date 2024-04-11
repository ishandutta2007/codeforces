#include <cstdio>
#include <cstring>
#define Maxn 1000000
int sum[Maxn<<2|5],ll[Maxn<<2|5],rr[Maxn<<2|5];
char s[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
void PushUp(int rt){
	int tmp=mn(ll[rt<<1],rr[rt<<1|1]);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1]+(tmp<<1);
	ll[rt]=ll[rt<<1]+ll[rt<<1|1]-tmp;
	rr[rt]=rr[rt<<1]+rr[rt<<1|1]-tmp;
}
void build(int l,int r,int rt){
	if(l==r){
		ll[rt]=rr[rt]=sum[rt]=0;
		if(s[l-1]=='('){
			ll[rt]=1;
		}
		else{
			rr[rt]=1;
		}
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	PushUp(rt);
}
int Query(int L,int R,int l,int r,int rt,int &lls,int &rrs){
	if(l>=L&&r<=R){
		lls=ll[rt];
		rrs=rr[rt];
		return sum[rt];
	}
	int m=(l+r)>>1;
	if(m>=R){
		return Query(L,R,l,m,rt<<1,lls,rrs);
	}
	else if(m<L){
		return Query(L,R,m+1,r,rt<<1|1,lls,rrs);
	}
	else{
		int sum1,sum2,ll2,rr2,tmp;
		sum1=Query(L,R,l,m,rt<<1,lls,rrs);
		sum2=Query(L,R,m+1,r,rt<<1|1,ll2,rr2);
		tmp=mn(lls,rr2);
		lls=lls+ll2-tmp;
		rrs=rrs+rr2-tmp;
		return sum1+sum2+(tmp<<1);
	}
}
int main(){
	int n;
	scanf("%s",s);
	n=strlen(s);
	build(1,n,1);
	int m,l,r,ll,rr;
	scanf("%d",&m);
	int ans;
	while(m--){
		scanf("%d%d",&l,&r);
		ans=Query(l,r,1,n,1,ll,rr);
		printf("%d\n",ans);
	}
	return 0;
}