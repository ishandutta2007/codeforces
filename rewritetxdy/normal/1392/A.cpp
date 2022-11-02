#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n,c[233333];

int main()
{
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]);
	int f=0;
		for(int i=1;i < n;i++) if(c[i] != c[i+1]){
			puts("1");
			f = 1;
			break;
	}
	if(!f)
		printf("%d\n",n);
	}	
	return 0;
}