#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> v;

int eval()
{
	int i;
	vector<int> need;
	int res=0;

	for(i=0;i<n;i++)
	{
		auto it=lower_bound(need.begin(),need.end(),v[i]);
		if(it==need.end())
			need.push_back(v[i]);
		else
			*it=min(*it,v[i]);
	}

	res=need.size();

	need.clear();
	reverse(v.begin(),v.end());

	for(i=0;i<n;i++)
	{
		auto it=lower_bound(need.begin(),need.end(),v[i]);
		if(it==need.end())
			need.push_back(v[i]);
		else
			*it=min(*it,v[i]);
	}

	reverse(v.begin(),v.end());

	res+=need.size();

	return res;
}

int main ()
{
	int i,j,p;

	cin>>n;

	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}

	p=(int)sqrt(n);

	int p2=n/p;

	for(i=1;i<=p2;i++)
	{
		for(j=i*p;j>=(i-1)*p+1;j--)
		{
			cout<<j<<" ";
			v.push_back(j);
		}
		j=i*p;
	}
	if(j!=n)
		for(i=n;i>j;i--)
		{
			cout<<i<<" ";
			v.push_back(i);
		}
	cout<<endl;

	//cout<<eval()<<endl;

	return 0;
}