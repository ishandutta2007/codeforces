#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n;
int vis[100005];
int prm[100005];

int main()
{
	cin>>n;
	if(n==1 || n==2)
	{
		cout<<1<<endl;
		rep(i,1,n) cout<<"1 ";
		cout<<endl;
		return 0;
	}
	rep(i,2,n+1)
	{
		if(!vis[i]) prm[++*prm]=i;
		rep(j,1,*prm)
		{
			if(i*prm[j]>n+1) break;
			vis[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
	cout<<2<<endl;
	rep(i,2,n+1) cout<<vis[i]+1<<' ';
	cout<<endl;
	return 0;
}