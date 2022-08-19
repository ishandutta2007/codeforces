#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <unordered_map>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
#define iter multiset<int>::iterator 
using namespace std;
multiset<int> x;
ll s[30];
void ins(int pl, int num)
{
	for(int i = 0; i < 30; i++)
		if(pl <= (1 << i))
			s[i] += num;
} 
int main()
{
	int qs;
	scanf("%d", &qs);		
	int sz = 0;
//	cout<<"ASDFASFD"<<endl;
	for(int i = 0; i < qs; i++)
	{
		char inp[3];
		int num;
		scanf("%s", inp);
		scanf("%d", &num);
		//cout<<inp[0]<<endl;
		int pl = 0;
		if(inp[0] == '+') pl = 1,//, cout<<"AS"<<endl, 
						x.insert(num);
		else pl = -1, x.erase(x.find(num));
		ins(num, num * pl);
		sz += pl;
		int ans = sz - 1;
		if(sz == 0) ans = 0;
		int lst = 0;
	//	cout<<"!@#!@#!@#!"<<s[2]<<endl;
		for(int i = 0; i < 30; i++)
		{
			ll n1 = s[i];
			if(!n1) continue;
			if(lst > (1 << i)) continue;
			int m1 = *x.upper_bound(1 << i);
			if(n1 * 2 < m1 && m1 != lst)
				lst = m1, ans--;//, cout<<i<<" "<<s[i]<<endl; 
		}
		printf("%d\n", ans);
	}
	return 0;
} 
/*
2 1 1 5

 
*/