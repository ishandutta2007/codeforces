//25mins
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

char ch[64][64];
int n,m;
int ma=10000,mz=0,na=10000,nz=0;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",ch[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(ch[i][j]=='*')
			{
				if(i<ma)ma=i;
				if(i>mz)mz=i;
				if(j<na)na=j;
				if(j>nz)nz=j;
			}
	for(int i=ma;i<=mz;i++)
	{
		for(int j=na;j<=nz;j++)
			printf("%c",ch[i][j]);
		printf("\n");
	}
	return 0;
}