//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[101], r[101];

struct Edge
{
	int to;
	int nxt;
}e[20001];
int ne, h[101];
inline void addedge(int u, int v)
{
	e[++ne].to = v;
	e[ne].nxt = h[u];
	h[u] = ne;
}
int l;
deque<string> q;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		r[i] = s[i];
		reverse(r[i].begin(), r[i].end());
		for(int j=1;j<=i;j++)
		{
			if(s[i].substr(0) == r[j].substr(0))
			{
				if(i != j) addedge(i, j);
				else if(q.empty()) q.push_front(s[i]), l += s[i].length();
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i])
		{
			int j = e[h[i]].to;
			q.push_front(s[i]);
			q.push_back(s[j]);
			l += s[i].length() + s[j].length();
		}
	}
	cout<<l<<endl;
	while(!q.empty())
	{
		cout<<q.front();
		q.pop_front();
	}
	cout<<endl;
	return 0;
}