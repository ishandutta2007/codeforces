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

#define maxn 105

int n,K;
char P[maxn],res[maxn],occ[maxn];

int main()
{
	scanf("%d%d",&n,&K);
	
	memset(res,' ',sizeof(res));
	
	scanf("%s",P);
	scanf("%s",occ);
	
	bool ok=true;
	
	for (int i=0;i<n;++i)
	if (occ[i]=='1')
	{
		for (int j=0;P[j];++j)
		if (i+j<n)
		{
			if (res[i+j]!=' ' && res[i+j]!=P[j]) ok=false;
			
			res[i+j]=P[j];
		}else ok=false;
	}
	
	for (int i=0;i<n;++i)
	if (occ[i]=='0')
	{
		bool fl=true;
		for (int j=0;P[j] && fl;++j)
		if (i+j<n)
		{
			if (res[i+j]==' ' || res[i+j]!=P[j])
			{
				fl=false;
				if (res[i+j]==' ')
				{
					if (P[j]=='a') res[i+j]='b';
					else res[i+j]='a';
				}
			}
		}else fl=false;
		
		if (fl) ok=false;
	}
	
	for (int i=0;i<n;++i)
	if (res[i]==' ')
	{
		if (P[0]=='a') res[i]='b';
		else res[i]='a';
	}
	res[n]=0;
	if (ok) puts(res);
	else puts("No solution");
	
	return 0;
}