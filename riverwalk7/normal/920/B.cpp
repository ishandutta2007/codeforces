#include<bits/stdc++.h>
#define int long long int 
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
const int maxn=1e3+5;
int ans[maxn];
int l[maxn],r[maxn];
main()
{
	ios_base::sync_with_stdio(false);
	int Q;
	cin>>Q;
	for(int T=1;T<=Q;T++)
	{
		vector<int> v[5*maxn];
		queue<int> q;
		int n;
		cin>>n;
		for(int i=0;i<=n+1;i++)
			ans[i]=0;
		for(int i=1;i<=n;i++)
			cin>>l[i]>>r[i],v[l[i]].push_back(i);
		for(int i=1;i<=5001;i++)
		{
			for(int j=0;j<v[i].size();j++)
				q.push(v[i][j]);
			while(q.size())
			{
				if(r[q.front()]<i)
					q.pop();
				else
					break;
			}
			if(q.size())
				ans[q.front()]=i,q.pop();
		}
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}