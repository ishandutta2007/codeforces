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
#define pii pair<int,int>
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
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

int n;
INT a[100007],S;
vector<INT> seq;

INT get_cost(int gursh)
{
	seq.clear();
	for(int i=1;i<=n;i++)
		seq.push_back(a[i]+1LL*i*gursh);
	sort(seq.begin(),seq.end());
	INT sum=0;
	for(int i=0;i<gursh;i++)
		sum+=seq[i];
	return sum;
}

int main()
{
	scanf("%d%I64d",&n,&S);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	int lft=0,rgt=n;
	while(lft<=rgt)
	{
		int mid=lft+rgt>>1;
		if(get_cost(mid)>S)rgt=mid-1;
		else lft=mid+1;
	}
	printf("%d %I64d\n",lft-1,get_cost(lft-1));
	return 0;
}