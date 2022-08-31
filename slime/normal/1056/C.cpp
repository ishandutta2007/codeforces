#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define maxs 17
#define ll long long
using namespace std;
int eg[maxn];
int p[maxn];
int fl[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int tt = 2 * n;
	for(int i = 1; i <= tt; i++)
		scanf("%d", &p[i]);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		eg[a] = b, eg[b] = a;
	}
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= tt; i++)
	{
		if(i % 2 == t % 2)
		{
			bool nf = 0;
			for(int i = 1; i <= tt; i++)
				if(fl[i] && eg[i] && !fl[eg[i]])
				{	
					cout<<eg[i]<<endl;
					fl[eg[i]] = 1;
					fflush(stdout);
					nf = 1;
					break;
				}
			if(nf) continue;
			for(int i = 1; i <= tt; i++)
				if(!fl[i] && eg[i] && p[i] >= p[eg[i]])
				{
					cout<<i<<endl;
					fl[i] = 1;
					fflush(stdout);
					nf = 1;
					break;
				}
			if(nf) continue;
			int ns = 0, pl = 0;
			for(int i = 1; i <= tt; i++)
			{
				if(fl[i]) continue;
				if(p[i] >= ns)
					ns = p[i], pl = i;
			}
			cout<<pl<<endl;
			fl[pl] = 1;
			fflush(stdout);
		}
		else
		{
			int k;
			cin>>k;
			fl[k] = 1;
		}
	}
	return 0;
}