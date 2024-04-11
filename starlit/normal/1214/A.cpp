#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	ans=n,b*=5;
	for(int i=0;i*b<=n;i++)
	ans=min(ans,(n-i*b)%a);
	printf("%d",ans);
}