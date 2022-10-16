#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int deg[2333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(deg,0,sizeof(deg));
		cin>>n>>k;
		int x,y;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			deg[x]++;deg[y]++;
		}
		if(deg[k]<=1)cout<<"Ayush"<<endl;
		else if(n%2==0)cout<<"Ayush"<<endl;
		else cout<<"Ashish"<<endl;
	}
	return 0;
}