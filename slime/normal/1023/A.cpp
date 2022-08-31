#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mod 998244353
#define maxn 500005
#define ll long long
#define ld long double
using namespace std;
char s[maxn], t[maxn];
bool check(int l, int r)
{
	for(int i = l; i <= r; i++)
		if(s[i] != t[i]) return 0;
	return 1;
	
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	scanf("%s", t);
	bool fl = 1;
	int pl = -1;
	for(int i = 0; i < n; i++)
		if(s[i] == '*') pl = i;//, cout<<"!!"<<i<<endl;
	if(pl == -1)
	{
		if(n != m) fl = 0;
		else if(!check(0, n - 1)) fl = 0;
	}
	else
	{
		if(n > m + 1)
		{
			printf("NO\n");
			return 0;
		}
		if(!check(0, pl - 1)) fl = 0;//, cout<<"!!!"<<endl;;
		for(int i = n - 1; i >= pl + 1; i--)
			if(s[i] != t[i + m - n]) fl = 0;//, cout<<"!!!"<<i<<endl;
	}
	if(fl) printf("YES\n");
	else printf("NO\n");
	return 0;
}