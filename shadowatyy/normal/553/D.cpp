#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

int n,m,k;
vector<int>graf[maxn];
bool den[maxn],inside[maxn];
int deg[maxn];
set<pair<double,int> >S;

bool check(double x)
{
	S.clear();
	for(int i=1;i<=n;i++)
	{
		if(!den[i]){
			deg[i]=0;
			for(int v:graf[i])
			{
				deg[i]+=!den[v];
			}
			S.insert({1.0*deg[i]/graf[i].size(),i});
			inside[i]=true;
		}
		else
		{
			inside[i]=false;
		}
	}
	while(S.size())
	{
		auto it=S.begin();
		if((*it).first>=x)
			return 1;
		int u=(*it).second;
		S.erase(it); inside[u]=0;
		for(int v:graf[u])
		{
			if(inside[v])
			{
				S.erase({1.0*deg[v]/graf[v].size(),v});
				deg[v]--;
				S.insert({1.0*deg[v]/graf[v].size(),v});
			}
		}
	}
	return false;
}
		
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	
	for(int i=0;i<k;i++)
	{
		int a; cin>>a;
		den[a]=true;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	double l=0,r=1;
	for(int i=0;i<28;i++)
	{
		double s=(l+r)/2;
		if(check(s))
			l=s;
		else
			r=s;
	}
	check(l);
	cout<<S.size()<<"\n";
	for(auto v:S)
	{
		cout<<v.second<<" ";
	}

	
	
	return 0;
}