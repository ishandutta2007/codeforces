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

int n,t[30000];
int maxn=-2000000000;

void Try(int a)
{
	if(n/a<=2)return;
	for(int i=0;i<a;i++)
	{
		int s=0;
		for(int j=i;j<n;j+=a)
			s+=t[j];
		if(s>maxn)maxn=s;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&t[i]);
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			Try(i);
			Try(n/i);
		}
	}
	printf("%d\n",maxn);
	return 0;
}