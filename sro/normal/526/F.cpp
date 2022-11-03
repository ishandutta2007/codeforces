#include <bits/stdc++.h>
using namespace std;

int n;
int a[300005],b[300005];
int l[300005],r[300005];
int sum[300005];

long long fendge(int nl,int nr){
	if(nl==nr){
		return 0;
	}
	int m=(nl+nr)>>1;
	long long ans=fendge(nl,m)+fendge(m+1,nr);
	l[m]=r[m]=m;
	int L=m,R=m;
	int sm=a[m],bg=a[m];
	for(int i=m-1;i>=nl;i--){
		int x=a[i];
		if(x<a[m]-(nr-nl)){
			x=a[m]-(nr-nl);
		}
		if(x>a[m]+(nr-nl)){
			x=a[m]+(nr-nl);
		}
		while(sm>x){
			sm--;
			int xx=b[sm];
			L=min(L,xx);
			R=max(R,xx);
		}
		while(bg<x){
			bg++;
			int xx=b[bg];
			L=min(L,xx);
			R=max(R,xx);
		}
		l[i]=L;
		r[i]=R;
	}
	L=R=m;
	sm=a[m],bg=a[m];
	for(int i=m+1;i<nr;i++){
		int x=a[i];
		if(x<a[m]-(nr-nl)){
			x=a[m]-(nr-nl);
		}
		if(x>a[m]+(nr-nl)){
			x=a[m]+(nr-nl);
		}
		while(sm>x){
			sm--;
			int xx=b[sm];
			L=min(L,xx);
			R=max(R,xx);
		}
		while(bg<x){
			bg++;
			int xx=b[bg];
			L=min(L,xx);
			R=max(R,xx);
		}
		l[i]=L;
		r[i]=R;
	}
	sum[m]=0;
	for(int i=m;i<=nr;i++){
		if(r[i]==i){
			sum[i+1]=sum[i]+1;
		}else{
			sum[i+1]=sum[i];
		}
	}
	int ff=m;
	for(int i=m;i>=nl;i--){
		if(l[i]!=i){
			continue;
		}
		while(ff+1<nr&&l[ff+1]>=i){
			ff++;
		}
		int mm=r[i];
		if(mm<=ff){
			ans+=sum[ff+1]-sum[mm];
		}
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=y;
		b[y]=x;
	}
	long long ans=fendge(1,n+1);
	printf("%lld\n",ans);
	return 0;
}