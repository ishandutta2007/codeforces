#include<map>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
string s,Tmp,value;
map<string,string>Hash;
vector<string>res;

int Find(string s,int x)
{
	if((int)s.size()==x)return 1;
	string t;
	for(int i=x;i<=(int)s.length()-1;i++)
	{
		t+=s[i];
		if(Hash.find(t)!=Hash.end())
		{
			res.push_back(Hash[t]);
			if(Find(s,i+1))return 1;
			else res.pop_back();
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	cin>>s;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		cin>>value;Tmp=value;
		reverse(Tmp.begin(),Tmp.end());
		transform(Tmp.begin(),Tmp.end(),Tmp.begin(),::tolower);
		Hash[Tmp]=value;
	}
	Find(s,0);
	for(int i=0;i<(int)res.size();i++)cout<<res[i]<<" ";
}