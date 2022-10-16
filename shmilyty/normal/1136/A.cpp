#include<bits/stdc++.h>
using namespace std;
int n,a,b,k;
vector<int> v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		v.push_back(b); 
	}
	scanf("%d",&k);
	for(int i=0;i<v.size();i++)
		if(v[i]>=k)
		{
			cout<<n-i;
			return 0;
		}
}