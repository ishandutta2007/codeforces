#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
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
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define _X first
#define _Y second
#define OVER(a) return puts(a),0
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

int n;
int a[1005],b[1005];
int hva[1005],hvb[1005];
vector<int> shaoa,shaob,hs;

int main()
{
	scanf("%d",&n);
	FILL0(hva);
	FILL0(hvb);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		hva[a[i]]++;
	for(int i=1;i<=n;i++)
		if(!hva[i]) shaoa.push_back(i);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]) hs.push_back(i);
	if(hs.size()==1)a[hs[0]]=shaoa[0];
	else
	{
		if(b[hs[0]]==shaoa[0]&&hva[a[hs[0]]]!=1||b[hs[0]]==shaoa[1]&&hva[a[hs[0]]]!=1)a[hs[0]]=b[hs[0]];
		else if(hs.size()==2&&(b[hs[1]]==shaoa[0]&&hva[a[hs[1]]]!=1||b[hs[1]]==shaoa[1]&&hva[a[hs[1]]]!=1))a[hs[1]]=b[hs[1]];
	}
	for(int i=0;i<n;i++)
		printf("%d%c",a[i],i==n-1?'\n':' ');
	return 0;
}