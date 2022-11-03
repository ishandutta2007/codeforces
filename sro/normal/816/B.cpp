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
#define FILL(a,v) memset((void*)a,v,sizeof(a))
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
#define MAXN 200007
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

int cando[MAXN];
int canbe[MAXN];
int st[MAXN],en[MAXN];
int n,k,q;
queue<int> inst;

int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0;i<n;i++)
		scanf("%d%d",&st[i],&en[i]);
	sort(st,st+n);
	sort(en,en+n);
	int l=st[0],K=0;
	for(int i=0;i<n;i++)
	{
		for(;st[K]<=en[i]&&K<n;K++)
		{
			int abcd=SZ(inst);
			for(;l<st[K];l++)
			{
				cando[l]=abcd;
				canbe[l]=canbe[l-1]+(cando[l]>=k?1:0);
			}
			inst.push(st[K]);
		}
		int abcd=SZ(inst);
		for(;l<=en[i];l++)
		{
			cando[l]=abcd;
			canbe[l]=canbe[l-1]+(cando[l]>=k?1:0);
		}
		inst.pop();
	}
	for(;l<MAXN;l++)
	{
		canbe[l]=canbe[l-1];
	}
	int a,b;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",canbe[b]-canbe[a-1]);
	}
	return 0;
}