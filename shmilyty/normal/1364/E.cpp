#include<bits/stdc++.h>
using namespace std;
int n,x,y,k,ans,a[2049];
int query(int f,int s)
{
	cout<<"? "<<f+1<<" "<<s+1<<endl;
	int res;
	scanf("%d",&res);
	return res;
}
bool c(int x)
{
	int sb=2047,t=30,rd;
	while(t--)
	{
		rd=rand()%n;
		while(rd==x)
			rd=rand()%n;
		sb&=query(rd,x);
	}
	return (sb==0);
}
int main()
{
	srand(time(NULL));
	scanf("%d",&n);
	x=0;
	y=1;
	k=query(x,y);
	for(int i=2;i<n;i++)
	{
		int k2=query(x,i);
		if(k2<=k)
		{
			int k3=query(y,i);
			if(k2<k3)
			{
				y=i;
				k=k2;
			}
			if(k3<k2)
			{
				x=i;
				k=k3;
			}
		}
	}
	if(c(x))
		ans=x;
	else
		ans=y;
	for(int i=0;i<n;i++)
		if(i!=ans)
			a[i]=query(ans,i);
	cout<<"! ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" "; 
	return 0;
}