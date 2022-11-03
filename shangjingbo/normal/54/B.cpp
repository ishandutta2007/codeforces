#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define maxn 25

set<string> hash;

char s[maxn][maxn],a[maxn][maxn];
int n,m,ox,oy;

inline string calc(char a[][maxn],int n,int m)
{
	string res="";
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
			res+=a[i][j];
		res+="$";
	}
	
	string s="";
	for (int j=0;j<m;++j)
	{
		for (int i=n-1;i>=0;--i)
			s+=a[i][j];
		s+="$";
	}
	res=min(res,s);
	
	s="";
	for (int i=n-1;i>=0;--i)
	{
		for (int j=m-1;j>=0;--j)
			s+=a[i][j];
		s+="$";
	}
	res=min(res,s);
	
	s="";
	for (int j=m-1;j>=0;--j)
	{
		for (int i=0;i<n;++i)
			s+=a[i][j];
		s+="$";
	}
	res=min(res,s);
	
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
		scanf("%s",s[i]);
	
	ox=n;
	oy=m;
	int cnt=0;
	for (int x=1;x<=n;++x)
	if (n%x==0)
		for (int y=1;y<=m;++y)
		if (m%y==0)
		{
			hash.clear();
			for (int i=0;i*x<n;++i)
				for (int j=0;j*y<m;++j)
				{
					for (int dx=0;dx<x;++dx)
						for (int dy=0;dy<y;++dy)
							a[dx][dy]=s[i*x+dx][j*y+dy];
					string key=calc(a,x,y);
					if (hash.count(key)) goto Break;
					hash.insert(key);
				}
			
			++cnt;
			if (x*y<ox*oy || x*y==ox*oy && x<ox) ox=x,oy=y;
			
			Break:;
		}
	
	printf("%d\n",cnt);
	printf("%d %d\n",ox,oy);
	
	return 0;
}