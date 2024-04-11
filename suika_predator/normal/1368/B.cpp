#include<bits/stdc++.h>
using namespace std;
char str[233]=" codeforces";
long long get(long long x,int y)
{
	long long ret=1;
	for(int i=1;i<=10;i++)
	{
		if(i<=y)ret*=x;
		else ret*=x-1;
	}
//	cerr<<"get "<<x<<' '<<y<<' '<<ret<<endl;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	long long n;
	cin>>n;
	for(int i=1;i<=40;i++)
	{
		if(get(i,10)>=n)
		{
			for(int j=1;j<=10;j++)
			{
				if(get(i,j)>=n)
				{
					for(int k=1;k<=10;k++)
					{
						if(k<=j)
							for(int l=1;l<=i;l++)
							{
								cout<<str[k];
							}
						else
							for(int l=1;l<=i-1;l++)
							{
								cout<<str[k];
							}
					}
					return 0;
				}
			}
		}
	}
	return 0;
}