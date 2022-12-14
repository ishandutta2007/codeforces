#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[100010];
int main()
{
	int n,l,x,y,n1;
	cin>>n>>l>>x>>y;
	for(n1=1;n1<=n;n1++)
		cin>>num[n1];
	int a=0,b=0,c=0,k,d=0,z,p;
	for(n1=1;n1<n;n1++)
	{
		int l=n1+1,r=n;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if((num[mid]-num[n1])>x)
				r=mid-1;
			else
				l=mid;
		}
		if(num[l]-num[n1]==x)
			a=1;
		l=n1+1,r=n;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if((num[mid]-num[n1])>y)
				r=mid-1;
			else
				l=mid;
		}
		if(num[l]-num[n1]==y)
			b=1;			
		l=n1+1,r=n;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if((num[mid]-num[n1])>x+y)
				r=mid-1;
			else
				l=mid;
		}
		if(num[l]-num[n1]==x+y)
		{
			c=1;
			k=num[n1];
		}
		l=n1+1,r=n;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if((num[mid]-num[n1])>y-x)
				r=mid-1;
			else
				l=mid;
		}
		if(num[l]-num[n1]==y-x&&d==0)
		{
			d=1;
			z=num[n1];
		}
		if(num[l]-num[n1]==y-x)
			p=num[n1];	
	}
	if(a&&b)
		cout<<0;
	else
		if(c)
			cout<<1<<endl<<k+x;
		else
			if(d&&z+y<=l)
				cout<<1<<endl<<z+y;
				else
					if(d&&p-x>=0)
						cout<<1<<endl<<p-x;
					else
			if(a)
				cout<<1<<endl<<y;
			else
				if(b)
					cout<<1<<endl<<x;
				else
					cout<<2<<endl<<x<<' '<<y;
}