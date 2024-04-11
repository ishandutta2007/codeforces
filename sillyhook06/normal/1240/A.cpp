#include<bits/stdc++.h>
#define LL long long
using namespace std;
int q,n,p[200020],a,b,con[200020],tmp1[200020],tmp2[200020];
LL k;
int cmp(int x,int y){
	return x>y;
}
LL get(int x){
	for (int i=1;i<=x;i++)tmp2[i]=con[i];
	sort(tmp2+1,tmp2+1+x,cmp);
	LL res=0;
	for (int i=1;i<=x;i++) res+=1ll*tmp1[i]*tmp2[i]/100;
	return res;
}
int main(){
	//freopen("A.in","r",stdin);
	scanf("%d",&q);
	while (q--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		for (int i=1;i<=n;i++) con[i]=0;
		scanf("%d%d",&a,&b);
		for (int i=b;i<=n;i+=b) con[i]+=a;
		scanf("%d%d",&a,&b);
		for (int i=b;i<=n;i+=b) con[i]+=a;
		scanf("%lld",&k);
		int l=1,r=n,res=n+1;
		for (int i=1;i<=n;i++) tmp1[i]=p[i];
		sort(tmp1+1,tmp1+1+n,cmp);
		while (l<=r){
			int mid=(l+r)/2;
			if (get(mid)>=k) r=mid-1,res=mid;
			else l=mid+1;
		}
		if (res>n) printf("-1\n");
		else printf("%d\n",res);
	}
}