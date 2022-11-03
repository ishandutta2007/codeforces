#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
pair<int,int> qjs[123];
bool ljd[123][123];
bool dfsed[123];
int n,cntal=0;
inline void dfs_it(int qj)
{
	dfsed[qj]=true;
	for(int i=0;i<cntal;i++)
		if(ljd[qj][i]&&!dfsed[i])dfs_it(i);
}

inline void _1()
{
	int x,y;
	scanf("%d %d",&x,&y);
	qjs[cntal++]=make_pair(x,y);
	#define A x
	#define B y
	for(int i=0;i<cntal-1;i++)
	{
		#define C qjs[i].first
		#define D qjs[i].second
		if(((((C<A)&&(A<D))||((C<B)&&(B<D)))||((((C<A)&&(B<D)))))||((((A<D)&&(D<B))||((A<C)&&(C<B)))||((((A<C)&&(D<B))))))
		{
			bool a=(((C<A)&&(B<D))),b=(((A<C)&&(D<B)));
			if(!a)ljd[i][cntal-1]=true;
			if(!b)ljd[cntal-1][i]=true;
		}
	}
}

inline void _2()
{
	int a,b;
	scanf("%d %d",&a,&b);
	memset(dfsed,0,sizeof(dfsed));
	dfs_it(--a);
	if(dfsed[--b]==true)puts("YES");
	else puts("NO");
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int _12;
		scanf("%d",&_12);
		_12==1?_1():_2();
	}
	return 0;
}