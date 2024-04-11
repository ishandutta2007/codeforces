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
#define OVER(a) return puts(a),0
using namespace std;
using namespace __gnu_cxx;

int n,w,a[150];
int giv[150];

int PAIXU_FUNCTION(int i,int j)
{
	return a[i]>a[j];
}

int main()
{
	scanf("%d%d",&n,&w);
	int ww=w;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	memset(giv,0,sizeof(giv));
	for(int i=0;i<n;i++)
	{
		giv[i]=(a[i]+1)/2;
		ww-=(a[i]+1)/2;
		if(ww<0) OVER("-1");
	}
	int shzu[150];
	for(int i=0;i<n;i++)shzu[i]=i;
	sort(shzu,shzu+n,PAIXU_FUNCTION);
	for(int i=0;i<n;i++)
	{
		if(a[shzu[i]]-giv[shzu[i]]<ww)
		{
			ww-=(a[shzu[i]]-giv[shzu[i]]);
			giv[shzu[i]]=a[shzu[i]];
		}
		else
		{
			giv[shzu[i]]+=ww;
			ww=0;
			break;
		}
	}
	if(ww) OVER("-1");
	for(int i=0;i<n;i++)
		printf("%d%c",giv[i],i==n-1?'\n':' ');
	return 0;
}