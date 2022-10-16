#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,m,S;
vector<int>V[maxn];

int col[maxn],pos[maxn];
queue<int>q;

int ans1,ans2,ans;
int a[maxn],an;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m>>S;
	for(int i=1;i<=m;i++)
	{
		int x,y; cin>>x>>y;
		V[x].push_back(y);
	}
	
	//col[S]=-1;
	for(int i=0;i<(int)V[S].size();i++)
	{
		int y=V[S][i];
		col[y]=i+1;
		pos[y]=S;
		q.push(y);
	}
	
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		for(auto y:V[x]) if(y!=S)
		{
			if(col[y])
			{
				if(col[y]!=col[x])
				{
					ans=y;
					ans1=x;
					ans2=pos[y];
					break;
				}
			}
			else
			{
				col[y]=col[x];
				pos[y]=x;
				q.push(y);
			}
		}
		if(ans) break;
	}
	
	if(ans) 
	{
		cout<<"Possible\n";
	
		a[an=1]=ans;
		for(int i=ans1;i!=S;i=pos[i]) a[++an]=i;
		a[++an]=S;	
		cout<<an<<endl;
		for(int i=an;i>=1;i--) cout<<a[i]<<" \n"[i==1];
		
		a[an=1]=ans;
		for(int i=ans2;i!=S;i=pos[i]) a[++an]=i;
		a[++an]=S;
		cout<<an<<endl;
		for(int i=an;i>=1;i--) cout<<a[i]<<" \n"[i==1];
	}
	else
	{
		cout<<"Impossible\n";
	}
	
	return 0;
}