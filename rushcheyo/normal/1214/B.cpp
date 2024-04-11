#include<bits/stdc++.h>
using namespace std;

int main(){
	int b,g,n,ans=0;
	scanf("%d%d%d",&b,&g,&n);
	for(int i=0;i<=n;++i)
		if(i<=min(b,n)&&i>=max(n-g,0)&&n-i>=max(n-b,0)&&n-i<=min(g,n))++ans;
	printf("%d\n",ans);
}