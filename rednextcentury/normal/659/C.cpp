#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int a[1000000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	sort(a,a+n);
	int last=0;
	a[n]=1000000001;
	for (int i=0;i<=n;i++)
	{
		for (int j=last+1;j<a[i];j++)
		{
			if (m>=j)
				m-=j,vec.push_back(j);
			else
				break;
		}
		last=a[i];
	}
	printf("%d\n",vec.size());
	for (int  i=0;i<vec.size();i++)
		printf("%d ",vec[i]);
	printf("\n");
}