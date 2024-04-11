#include<bits/stdc++.h>
const int M=998244353;
using namespace std;
int a,b,ans=1;
int main(){
	scanf("%d%d",&a,&b);
	for(int i=0;i<a+b;i++)
	(ans+=ans)>=M?ans-=M:0;
	printf("%d",ans);
}