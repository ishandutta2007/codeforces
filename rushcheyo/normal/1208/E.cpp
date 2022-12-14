#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,w,l,a[1000005];
ll ans[1000005];

void upd(int l,int r,int v){
	if(l>r)return;
	ans[l]+=v;
	if(r<w)ans[r+1]-=v;
}

int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i){
		scanf("%d",&l);
		a[0]=a[l+1]=0;
		for(int j=1;j<=l;++j)scanf("%d",a+j);
		static int q[1000005];
		int st=0,ed=0;
		q[ed++]=0;
		for(int j=1;j<=l;++j){
			while(st<ed&&q[st]<max(0,j-(w-l)))++st;
			while(st<ed&&a[q[ed-1]]<=a[j])--ed;
			q[ed++]=j;
			upd(j,j,a[q[st]]);
		}
		upd(l+1,w-l,a[q[st]]);
		while(st<ed&&a[q[ed-1]]<=a[l+1])--ed;
		q[ed++]=l+1;
		for(int j=max(l+1,w-l+1);j<=w;++j){
			while(st<ed&&q[st]<max(0,j-(w-l)))++st;
			upd(j,j,a[q[st]]);
		}
	}
	for(int i=1;i<=w;++i)printf("%lld ",ans[i]+=ans[i-1]);
	puts("");
}