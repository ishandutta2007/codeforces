#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		vector<vector<int>> a(n+5,vector<int>(m+5));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		int ok=1,l=1,r=1;
		for(int i=1;i<=n;i++)
		{
			if(not is_sorted(a[i].begin()+1,a[i].begin()+m+1))
			{
				vector<int> b=a[i];
				sort(b.begin()+1,b.begin()+m+1);
				vector<int> sp;
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]!=b[j])
						sp.push_back(j);
				}
				if((int)sp.size()>2)
				{
					ok=0;
				}
				else l=sp[0],r=sp[1];
				break;
			}
		}
		for(int i=1;i<=n;i++)swap(a[i][l],a[i][r]);
		for(int i=1;i<=n;i++)
		{
			if(not is_sorted(a[i].begin()+1,a[i].begin()+m+1))
				ok=0;
		}
		if(ok)cout<<l<<' '<<r<<"\n";
		else cout<<-1<<"\n";
	}
	
	return 0;
}