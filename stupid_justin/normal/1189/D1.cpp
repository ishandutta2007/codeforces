#include <bits/stdc++.h>
using namespace std;
vector<int> p[100005];
int n,u,v;
int main() {
	cin>>n;
	for (int i=1;i<n;i++)
	{
		cin>>u>>v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (int i=1;i<=n;i++)
	  if (p[i].size()==2)
	  {
	  	cout<<"NO"<<endl;
	  	return 0;
	  }
	cout<<"YES"<<endl;

	return 0;
}