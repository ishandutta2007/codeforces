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
#define pob pop_back
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
#define FI first
#define SE second
#define OVER(a) return puts(a),0
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

int n,k;
string strs="aeiou";

string gest(string a)
{
	int shy=k;
	int i;
	for(i=SZ(a);i>=0;i--)
	{
		if(strs.find(a[i])!=string::npos)
			shy--;
		if(shy==0)break;
	}
	if(i<0)return "WRONG";
	return a.substr(i,SZ(a)-i);
}

bool pnd(string a,string b)
{
	a=gest(a);
	b=gest(b);
	if(a=="WRONG"||b=="WRONG")return false;
	return a==b;
}

int lix(vector<string> vs)
{
	if(pnd(vs[0],vs[1])&&pnd(vs[2],vs[3])&&pnd(vs[1],vs[2]))return -1;
	else if(pnd(vs[0],vs[1])&&pnd(vs[2],vs[3]))return 1;
	else if(pnd(vs[0],vs[2])&&pnd(vs[1],vs[3]))return 2;
	else if(pnd(vs[0],vs[3])&&pnd(vs[1],vs[2]))return 3;
	return -10000;
}

int main()
{
	scanf("%d%d",&n,&k);
	vector<vector<string> > str(n);
	string buf;
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++)
		{
			cin>>buf;
			str[i].push_back(buf);
		}
	int gue=-1;
	for(int i=0;i<n;i++)
	{
		int bx=lix(str[i]);
		if(bx<-1)
		{
			puts("NO");
			return 0;
		}
		if(bx==-1)continue;
		if(gue!=-1&&bx!=gue)
		{
			puts("NO");
			return 0;
		}
		gue=bx;
	}
	if(gue==-1)puts("aaaa");
	else if(gue==1)puts("aabb");
	else if(gue==2)puts("abab");
	else if(gue==3)puts("abba");
	return 0;
}