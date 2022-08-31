#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int ok[31416];

int main()
{
	int a[4], x, y;
	scanf("%d %d %d %d %d %d",a,a+1,a+2,a+3,&x,&y);
	sort(a,a+4);
	do
	{
		for(int i=x;i<=y;i++)
		{
			int mod = i%a[0]%a[1]%a[2]%a[3];
			if(mod==i) ok[i]++;
		}
	}while(next_permutation(a,a+4));
	
	int ans = 0;
	for(int i=x;i<=y;i++) if(ok[i]>=7) ans++;
	
	printf("%d\n",ans);
	
	return 0;
}