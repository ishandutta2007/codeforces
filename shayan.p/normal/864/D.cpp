#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[300000];
int main()
{
	stack<int> s;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	num[a[i]]++;
	}
	for(int i=n;i>0;i--)
	if(num[i]==0)
	s.push(i);
	int q=0;
	for(int i=0;i<n;i++)
	{
		if((num[a[i]]>1&&a[i]>s.top())||num[a[i]]==500000)
		{num[s.top()]=1;(num[a[i]]==500000)?:num[a[i]]--;a[i]=s.top();q++;s.pop();}
		else
		num[a[i]]=500000;
	}
		cout<<q<<endl;
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}