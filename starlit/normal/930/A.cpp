#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,f,d[N],sum;
bool s[N];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&f);
		s[d[i]=d[f]+1]^=1;
	}
	for(int i=1;i<=n;i++)sum+=s[i];
	printf("%d",sum+1);
}