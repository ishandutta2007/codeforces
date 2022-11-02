#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5+10;
const double eps = 1e-12;

int n,x[N],y[N];

int main()
{
	scanf("%d",&n);
	if(n&1){
		puts("NO");
		return 0;
	}
	for(int i=1;i <= n;i++)
		scanf("%d%d",&x[i],&y[i]);
	n >>= 1;
	int midx = (x[1]+x[n+1]),midy = (y[1]+y[n+1]); 
	for(int i=1;i <= n;i++)
		if((x[i]+x[n+i])-midx != 0 || (y[i]+y[n+i])-midy != 0){
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}