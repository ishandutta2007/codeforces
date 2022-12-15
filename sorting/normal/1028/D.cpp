#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

struct cmp
{
	bool operator()(long long a, long long b)
	{
		return a>b;
	}
};

const long long mod = 1e9 + 7;

vector<long long> uncertain;
priority_queue<long long>sm;
priority_queue<long long, vector<long long>, cmp>bg;

long long fastPow(long long base,long long exp)
{
	if(exp==0)
		return 1;

	long long res=1,k;

	if(exp%2==1)
		res=base;

	k=fastPow(base,exp/2);
	k*=k;

	k%=mod;

	res*=k;

	res%=mod;

	return res;
}

int main ()
{
	long long n,i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	long long p,res=1;
	string s;

	for(i=0;i<n;i++)
	{
		cin>>s>>p;

		if(s=="ADD")
		{
			if(!sm.empty() && p<=sm.top())
			{
				sm.push(p);
				continue;
			}
			if(!bg.empty() && p>=bg.top())
			{
				bg.push(p);
				continue;
			}

			uncertain.push_back(p);
		}
		else
		{
			if((!sm.empty() && p<sm.top()) || (!bg.empty() && p>bg.top()))
			{
				cout<<"0\n";
				return 0;
			}

			if(!sm.empty() && p==sm.top())
			{
				sm.pop();

				while(!uncertain.empty())
				{
					bg.push(uncertain.back());
					uncertain.pop_back();
				}

				continue;
			}

			if(!bg.empty() && p==bg.top())
			{
				bg.pop();

				while(!uncertain.empty())
				{
					sm.push(uncertain.back());
					uncertain.pop_back();
				}

				continue;
			}

			res*=2;
			while(res>=mod)
				res-=mod;

			while(!uncertain.empty())
			{
				if(uncertain.back()<p)
					sm.push(uncertain.back());
				else
					if(uncertain.back()>p)
						bg.push(uncertain.back());

				uncertain.pop_back();
			}
		}
	}

	if(!uncertain.empty())res*=(uncertain.size()+1);
	res%=mod;

	cout<<res<<"\n";

	return 0;
}