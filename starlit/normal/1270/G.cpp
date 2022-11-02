#include<bits/stdc++.h>
const int N=1000006;
using namespace std;
int T,n,a[N],dfn[N],t;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);t=0;
		for(int i=1;i<=n;i++)
		scanf("%d",a+i),dfn[i]=0;
		for(int i=1;;i-=a[i])
		if(dfn[i]){
			printf("%d\n%d",t-dfn[i]+1,i);
			for(int j=i-a[i];j!=i;j-=a[j])
			printf(" %d",j);
			puts("");
			break;
		}else dfn[i]=++t;
	}
}