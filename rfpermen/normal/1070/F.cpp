#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pqa, pqb, pqn;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string S;
	int inp;
	int hasil=0, ca=0, cb=0;
	int cnt=0;
	for(int a=0;a<n;a++)
	{
		cin>>S>>inp;
		if(S=="11")
		{
			hasil+=inp;
			ca++;
			cb++;
			cnt++;
		}
		else if(S=="01")
		{
			pqb.push(inp);
		}
		else if(S=="10")
		{
			pqa.push(inp);
		}
		else
		{
			pqn.push(inp);
		}
	}
	while(!pqa.empty() && !pqb.empty())
	{
		hasil+=pqa.top()+pqb.top();
		pqa.pop();
		pqb.pop();
		ca++;cb++;
		cnt+=2;
	}
	while(!pqa.empty() && !pqn.empty() && ca*2>cnt && cb*2>cnt)
	{
		if(pqa.top()>pqn.top())
		{
			hasil+=pqa.top();
			pqa.pop();
			ca++;
			cnt++;
		}
		else
		{
			hasil+=pqn.top();
			pqn.pop();
			cnt++;
		}
	}
	while(!pqb.empty() && !pqn.empty() && ca*2>cnt && cb*2>cnt)
	{
		if(pqb.top()>pqn.top())
		{
			hasil+=pqb.top();
			pqb.pop();
			cb++;
			cnt++;
		}
		else
		{
			hasil+=pqn.top();
			pqn.pop();
			cnt++;
		}
	}
	while(ca*2>cnt && cb*2>cnt && !pqa.empty())
	{
		hasil+=pqa.top();
		pqa.pop();
		ca++;
		cnt++;
	}
	while(ca*2>cnt && cb*2>cnt && !pqb.empty())
	{
		hasil+=pqb.top();
		pqb.pop();
		cb++;
		cnt++;
	}
	while(ca*2>cnt && cb*2>cnt && !pqn.empty())
	{
		hasil+=pqn.top();
		pqn.pop();
		cnt++;
	}
	printf("%d\n", hasil);
	return 0;
}