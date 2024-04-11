#include <bits/stdc++.h>
using namespace std;
const int N=300005,T=50;
typedef long long ll;
int n,a[N],p[N],l[N],r[N];
bool cmp(int p,int q) {return a[p]<a[q];}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",a+i);
		p[i]=i,l[i]=i-1,r[i]=i+1;
	}
	sort(p+1,p+1+n,cmp);
	double ans=0;
	for (int i=1;i<=n;i++) {
		double ls=0,rs=0,pw=1;
		for (int j=1,x=p[i];x&&j<=T;j++,x=l[x],pw/=2) ls+=(x-l[x])*pw;
		pw=1;
		for (int j=1,x=p[i];x<=n&&j<=T;j++,x=r[x],pw/=2) rs+=(r[x]-x)*pw;
		ans+=a[p[i]]*ls*rs/2;
		r[l[p[i]]]=r[p[i]],l[r[p[i]]]=l[p[i]];
	}
	printf("%.10f\n",ans/n/n);
}