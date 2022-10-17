#include<iostream>
#include<vector>
using namespace std;

int n,k,m,t;
vector<int>v;

int main()
{
	cin>>n>>k>>m>>t;
	for(int i=1;i<=n;i++)
		v.push_back(i==k);
	for(int i=0;i<t;i++)
	{
		int opt,x;
		cin>>opt>>x;
		if(opt)
		{
			v.insert(v.begin()+x-1,0);
			cout<<v.size()<<' ';
			for(int j=0;j<v.size();j++)
				if(v[j])
					cout<<j+1<<endl;
		}
		else
		{
			int isdoc=0;
			for(int j=0;j<x;j++)
				isdoc+=v[j];
			if(isdoc)
				while(v.size()>x)
					v.pop_back();
			else
			{
				for(int j=0;j<v.size()-x;j++)
					v[j]=v[j+x];
				while(x--)
					v.pop_back();
			}
			cout<<v.size()<<' ';
			for(int j=0;j<v.size();j++)
				if(v[j])
					cout<<j+1<<endl;
		}
	}
}