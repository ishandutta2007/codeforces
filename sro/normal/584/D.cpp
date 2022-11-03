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

vector<int> zs;
bool iszhsh(int a)
{
	if(a==0||a==1)return false;
	int can=true;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)can=false;
	}
	return can;
}

int main()
{
	int k;
	scanf("%d",&k);
	zs.push_back(2);
	if(iszhsh(k))return printf("1\n%d\n",k),0;
	else if(iszhsh(k-2))return printf("2\n2 %d\n",k-2),0;
	else if(iszhsh(k-4))return printf("3\n2 2 %d\n",k-4),0;
	k-=3;
	for(int i=2;i<k-3;i++)
		if(iszhsh(k-i)&&iszhsh(i))
			return printf("3\n3 %d %d",i,k-i),0;//
}