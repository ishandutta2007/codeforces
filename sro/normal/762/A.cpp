#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;

vector<ll> vs;
ll n,k;

bool ifok()
{
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			vs.push_back(i);
			if((i*i)!=n)
				vs.push_back(n/i);
		}
	}
	if(k>vs.size()) return false;
	sort(vs.begin(),vs.end());
	return true;
} 

int main()
{
	cin>>n>>k;
	if(!ifok())return puts("-1");
	cout<<vs[k-1]<<endl;
	return 0;
}