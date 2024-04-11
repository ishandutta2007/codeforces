#include<bits/stdc++.h>

using namespace std;

int n,c,x;

long long ans;

int main(){

	scanf("%d%d",&n,&c),ans=abs(c);

	while(--n){

		scanf("%d",&x);

		ans+=abs(x-c);

		c=x;

	}

	printf("%I64d\n",ans);

	return 0;

}