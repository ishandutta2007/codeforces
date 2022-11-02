#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,l,r;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&r);
		if(r >= l*2)
			printf("%d %d\n",l,l*2);
		else
			puts("-1 -1");
	}
}