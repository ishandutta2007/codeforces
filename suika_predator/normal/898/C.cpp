#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int n,m;
unordered_map<string,unordered_set<string>> phone;
bool cmp(string s,string t)
{
	int ls=s.length(),lt=t.length();
	if(ls>lt)swap(s,t),swap(ls,lt);
	for(int i=ls-1,j=lt-1;i>=0;i--,j--)
	{
		if(s[i]!=t[j])return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	string name,tel;
	for(int i=1;i<=n;i++)
	{
		cin>>name>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>tel;
			int flag=0;
			for(auto x:phone[name])
			{
				if(tel.length()>x.length()&&cmp(x,tel))
				{
					phone[name].erase(x);
					phone[name].insert(tel);
					flag=1;
					break;
				}
				else if(cmp(x,tel))
				{
					flag=1;
					break;
				}
			}
			if(!flag)phone[name].insert(tel);
		}
	}
	cout<<phone.size()<<endl;
	for(auto x:phone)
	{
		cout<<x.first<<' '<<x.second.size();
		for(auto xx:x.second)
		{
			cout<<' '<<xx;
		}
		cout<<endl;
	}
	return 0;
}