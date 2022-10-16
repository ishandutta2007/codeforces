#include<bits/stdc++.h>
using namespace std;
int n;
int query(int a,int b,int c,int d)
{
	if(a<1 or a>n or b<1 or b>n or c<1 or c>n or d<1 or d>n)return 0;
	cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	string res;
	cin>>res;
	return res=="YES";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	int cx=1,cy=1;
	vector<pair<int,int>> pos;
	pos.emplace_back(1,1);
	while(cx+cy<n+1)
	{
		if(query(cx+1,cy,n,n))cx++;
		else cy++;
		pos.emplace_back(cx,cy);
	}
	cx=n,cy=n;
	pos.emplace_back(n,n);
	while(cx+cy>n+1)
	{
		if(query(1,1,cx,cy-1))cy--;
		else cx--;
		pos.emplace_back(cx,cy);
	}
	sort(pos.begin(),pos.end());
	pos.resize(unique(pos.begin(),pos.end())-pos.begin());
	cout<<"! ";
	for(int i=0;i+1<(int)pos.size();i++)
	{
		if(pos[i].first!=pos[i+1].first)cout<<"D";
		else cout<<"R";
	}
	cout<<endl;
	return 0;
}