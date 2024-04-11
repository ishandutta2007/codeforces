#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1005;
int n,m,c,p,a[N];

int main()
{
	cin>>n>>m>>c;
	rep(i,1,m)
	{
		cin>>p;
		if(p<=(c>>1))
		{
			rep(j,1,n)
				if(a[j]==0 || a[j]>p)
				{
					a[j]=p,cout<<j<<endl;
					break;
				}
		}
		else
		{
			repd(j,n,1)
				if(a[j]==0 || a[j]<p)
				{
					a[j]=p,cout<<j<<endl;
					break;
				}
		}
	}
	return 0;
}