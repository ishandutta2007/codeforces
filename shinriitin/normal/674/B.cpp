#include <bits/stdc++.h>

const int max_N = 1e3 + 21;

int a,b,c,d,n,k,tot,q[max_N];

int main(){
	scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
	if(n==4||k<=n)return puts("-1"),0;
	for(int i=1;i<=n;++i)
		if(i!=a&&i!=b&&i!=c&&i!=d){
			q[++tot]=i;	
		}
	printf("%d %d",a,c);
	for(int i=1;i<=tot;++i)printf(" %d",q[i]);
	printf(" %d %d\n",d,b);
	printf("%d %d",c,a);
	for(int i=1;i<=tot;++i)printf(" %d",q[i]);
	printf(" %d %d\n",b,d);
	return 0;
}