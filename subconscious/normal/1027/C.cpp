#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int n,T;
int a[1000005];
int b[1000005],top;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		rep(i,n)scanf("%d",a+i);
		sort(a+1,a+n+1);
		;top=0;
		rep(i,n)if(i>1&&a[i]==a[i-1])b[++top]=a[i],a[i]=a[i-1]=-1;
		int s=2;
		for(int i=3;i<=top;++i){
			if(1ll*b[s]*b[i-1]>1ll*b[i]*b[s-1])s=i;
		}
		printf("%d %d %d %d\n",b[s],b[s],b[s-1],b[s-1]);
	}
}