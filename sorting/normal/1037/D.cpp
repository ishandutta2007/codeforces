#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#define endl "\n"

using namespace std;

const long long N = 2e5 + 7;

long long n;
vector<long long> v[N];
long long e[N];
long long a[N];
bool used[N];
long long pos[N];

bool bfs(long long u)
{
	queue<long long> q;

	q.push(u);

	used[u]=1;

	long long timer=1,i;
	long long cnt,maxTimer;

	while(!q.empty())
	{
		u=q.front();
		q.pop();

		//cout<<u<<endl;

		cnt=0;
		maxTimer=timer-1;

		for(i=0;i<v[u].size();i++)
		{
			long long to=v[u][i];

			if(!used[to])
			{
				maxTimer=max(maxTimer,pos[to]);
				cnt++;
			}
		}

		//cout<<cnt<<" "<<maxTimer<<endl;

		if(cnt+timer-1!=maxTimer)
			return 0;

		for(i=timer;i<=maxTimer;i++)
		{
			//cout<<i<<" - "<<a[i]<<endl; 
			used[a[i]]=1;

			//cout<<"push "<<a[i]<<endl;
			q.push(a[i]);
		}

		timer=maxTimer+1;
	}

	return 1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long i;

	cin>>n;

	for(i=0;i<n-1;i++)
	{
		long long x,y;

		cin>>x>>y;

		v[x].push_back(y);
		v[y].push_back(x);

		e[x]++;
		e[y]++;
	}

	for(i=0;i<n;i++)
		cin>>a[i];

	for(i=0;i<n;i++)
		pos[a[i]]=i;

	if(a[0]!=1)
	{
		cout<<"No"<<endl;
		return 0;
	}

	if(bfs(a[0]))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}
/*
4
1 2
2 3
2 4
1 2 4 3
*/