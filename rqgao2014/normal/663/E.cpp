#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,k,si[1050005];
ll a[1050005],b[1050005];
char s[20][100005];

inline void fwt(ll *a,int l,int r){
	if(l==r) return;
	int mid=l+r>>1;
	fwt(a,l,mid),fwt(a,mid+1,r);
	for(int i=l;i<=mid;i++){
		ll x=a[i],y=a[i+mid-l+1];
		a[i]=x+y,a[i+mid-l+1]=x-y;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++){
		int t=0;
		for(int j=1;j<=n;j++)
			t=t*2+s[j][i]-'0';
		a[t]++;//printf("%d ",t);
	}//puts("");
	k=(1<<n)-1;
	for(int i=1;i<=k;i++) si[i]=si[i^(i&-i)]+1;
	for(int i=0;i<=k;i++) b[i]=max(si[i],n-si[i]);
	fwt(a,0,k);fwt(b,0,k);
	for(int i=0;i<=k;i++) a[i]=a[i]*b[i];
	fwt(a,0,k);
	int ans=0;
	for(int i=0;i<=k;i++) ans=max(ans,(int)(a[i]/(k+1)));
	printf("%d\n",n*m-ans);
	return 0;
}
/*
3 4
0110
1010
0111
*/