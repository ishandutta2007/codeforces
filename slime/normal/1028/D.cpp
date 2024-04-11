#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 1000000007
#define iter set<int>::iterator 
using namespace std;
set<int> ns[3];
char inp[10];
int main()
{
	ll ans = 1;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		int t;
		scanf("%s", inp);
		scanf("%d", &t);
		if(inp[1] == 'D')
		{
			if(!ns[0].empty() && t < *(--ns[0].end())) ns[0].insert(t);
			else if(!ns[1].empty() && t > *(ns[1].begin())) ns[1].insert(t);
			else ns[2].insert(t);
		}
		else
		{
			for(iter i = ns[2].begin(); i != ns[2].end(); i++)
				if(*i > t) ns[1].insert(*i);
				else if(*i < t) ns[0].insert(*i);
				else ans *= 2, ans %= mod;
			ns[2].clear();
			if(!ns[0].empty())
				if(t == *(--ns[0].end())) ns[0].erase(t);
				else if(t < *(--ns[0].end())) ans = 0;
			if(!ns[1].empty())
				if(t == *ns[1].begin()) ns[1].erase(t);
				else if(t > *ns[1].begin()) ans = 0;
		}
	}
	ans *= ns[2].size() + 1, 
	ans %= mod; 
	printf("%lld\n", ans);
	return 0;
} 
/*
2 1 1 5

 
*/