#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,f[100001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		f[i]+=f[i-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&l,&r);
		cout<<(f[r]-f[l-1])/10<<endl;
	}
	return 0;
}