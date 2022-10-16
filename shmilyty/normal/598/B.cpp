#include<bits/stdc++.h>
using namespace std;
string s;
int q,m,l,r,k;
char c[10001];
void work(int l,int r,int k)
{
	m=r-l+1;
	for(int i=l;i<=r;i++)
		c[(i-l+k)%m]=s[i];
	for(int i=l;i<=r;i++)
		s[i]=c[i-l];
	return ;
}
int main()
{
	cin>>s;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&k);
		work(l-1,r-1,k);
	}
	cout<<s;
	return 0;
}