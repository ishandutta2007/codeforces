#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[2333],vis[2333];
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		ans.clear();
		cin>>n;
		int ok=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=i-1)ok=0;
		}
		while(!ok)
		{
			int mex=0;
			for(int i=0;i<=n;i++)vis[i]=0;
			for(int i=1;i<=n;i++)vis[a[i]]=1;
			while(vis[mex])mex++;
			if(mex==n)
			{
				int fl=0;
				for(int i=1;i<=n;i++)
				{
					if(a[i]!=i-1)
					{
						ans.push_back(i);
						a[i]=mex;
						fl=1;
						break;
					}
				}
				if(!fl)ok=1;
			}
			else
			{
				ans.push_back(mex+1);
				a[mex+1]=mex;
			}
		}
		cout<<ans.size()<<endl;
		for(auto x:ans)cout<<x<<' ';
		cout<<endl;
//		cerr<<"final: ";for(int i=1;i<=n;i++)cerr<<a[i]<<' ';cerr<<endl;
	}
	return 0;
}