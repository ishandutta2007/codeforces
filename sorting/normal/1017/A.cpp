#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> > v;

bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first>b.first)
		return 1;
	if(a.first<b.first)
		return 0;
	return a.second<b.second;
}

int main ()
{
	int n,i,a,b,c,d;

	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c>>d;

		v.push_back(make_pair(a+b+c+d,i+1));
	}

	sort(v.begin(),v.end(),cmp);

	for(i=0;i<n;i++)
		if(v[i].second==1)
		{
			cout<<i+1<<endl;
			return 0;
		}

	return 0;
}