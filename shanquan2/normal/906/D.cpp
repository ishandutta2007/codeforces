#include<bits/stdc++.h>
using namespace std;

int n,m,p[1005],k,a[100005],b[100005];
int fexp(int x,int t,int m){
	if(!t)return 1;
	int tmp=fexp(x,t>>1,m);
	tmp=1ll*tmp*tmp%m;
	return (t&1)?1ll*tmp*x%m:tmp;
}
bool le(int l,int r,int m){
	if(r-l>=7)return 1;
	long long now=1;
	for(int i=r;i>=l;i--){
		if(now>=30)return 1;
		long long t=1;
		for(int j=0;j<now;j++){
			t=t*a[i];
			if(t>=m)return 1;
		}
		now=t;
	}
	return 0;
}
int gao(int l,int r,int k){
	if(l>r)return 1;
	if(p[k]==1)return 0;
	bool g=le(l+1,r,p[k]);
	if(g)return fexp(a[l],p[k+1]+gao(l+1,r,k+1),p[k]);
	else return fexp(a[l],gao(l+1,r,k),p[k]);
}
int main(){
	scanf("%d%d",&n,&m);
	p[0]=m;
	for(int x=m,i=1;x!=1;i++){
		int y=1;
		for(int j=2;j*j<=x;j++)if(x%j==0){
			y*=j-1;x/=j;
			while(x%j==0){
				x/=j;
				y*=j;
			}
		}
		if(x>1){
			y*=x-1;
		}
		x=y;
		p[i]=x;
	}
//	for(int i=0;i<10;i++)printf("%d ",p[i]);printf("\n");
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	b[n+1]=n+1;
	for(int i=n;i;i--){
		b[i]=b[i+1];
		if(a[i]==1)b[i]=i;
	}
	int q;scanf("%d",&q);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		if(m==1){
			printf("0\n");
			continue;
		}
		if(b[l]<=r)r=b[l]-1;
		if(a[l]==1){
			printf("%d\n",1);
			continue;
		}
		printf("%d\n",gao(l,r,0));
	}
	return 0;
}