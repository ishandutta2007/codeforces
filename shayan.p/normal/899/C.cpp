#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x;
	cin>>x;
	if(x==1)
	{
		cout<<"1"<<endl;
		cout<<"1 1";
		return 0;
	}
	stack <int> S;
	long long sum;
	sum=(x+1)*(x)/2;
	if(sum%2==0)
		cout<<"0"<<endl;
	else
		cout<<"1"<<endl;
	sum/=2;
	for(int i=x;i>0;i--)
	{
		if((sum-i)>=0)
		{
			sum=sum-i;
			S.push(i);
		}
	}
	cout<<S.size()<<" ";
	int j=S.size();
	for(int i=0;i<j;i++)
	{
		cout<<S.top()<<" ";
		S.pop();
	}
}