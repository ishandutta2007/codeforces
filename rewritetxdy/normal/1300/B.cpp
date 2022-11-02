#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 2e5+10;

int t,n,c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= (n<<1);i++)
			scanf("%d",&c[i]);
		sort(c+1,c+1+(n<<1));
		printf("%d\n",c[n+1]-c[n]);
	}
	return 0;
}