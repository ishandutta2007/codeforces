#include<bits/stdc++.h>
using namespace std;
int t,n,a,num[200001];
void solve()
{
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	bool flag=1; 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a); 
		a+=i;
		a=(a%n+n)%n;
		if(num[a])
			flag=0;
		num[a]++;
	}
	puts(flag?"YES":"NO");
}
int main()
{	
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
} //1