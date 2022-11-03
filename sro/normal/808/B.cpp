#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define INT long long
#define UINT unsigned long long
#define Uint unsigned int
#define PII pair<INT,INT>
#define SZ(a) ((int)(a).size())
#define _X first
#define _Y second
using namespace std;
using namespace __gnu_cxx;

INT n,k;
INT a[1000007];
INT freq[1000007];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	INT sum=0;
	for(int i=0;i<n;i++)
		if(i<k)freq[i]=i+1;
		else freq[i]=k;
	for(int i=n-1;i>=0;i--)
	{
		if(i>=n-k)freq[i]=min(freq[i],n-i);
		else freq[i]=min(freq[i],k);
		if(freq[i]>n-k+1)freq[i]=n-k+1;
	}
	for(int i=0;i<n;i++)
	{
		sum+=a[i]*freq[i];
	}
	double aver;
	aver=1.00*sum/(n-k+1);
	printf("%.9lf",aver);
	return 0;
}