/*

short-32768~32767
unsigned short0~65535
int-2147483648~2147483647
uint0~4294967295
INT-9223372036854775808~9223372036854775807
UINT0~18446744073709551615
float-3.4e383.4e386~7
double-1.7e308~1.7e30815~16
ldouble-1.2e4932~1.2e493218~19
*/
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
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

int v[500005];
int n,a,b,t;
char vv[500005];
int qzh[500005];

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&t);
	scanf("%s",vv);
	for(int i=0;i<n;i++)
		v[i]=(vv[i]=='h'?1:b+1);
	if(v[0]>t)
	{
		puts("0");
		return 0;
	}
	int ans=0;
	for(int dxx=0;dxx<2;dxx++)
	{
		qzh[0]=0;
		for(int i=1;i<n;i++)
			qzh[i]=qzh[i-1]+v[i]+a;
		v[n]=v[0];
		int sp=0,cs=0;
		for(int i=n;i>0;i--)
		{
			sp+=v[i];
			cs++;
			if(sp>t)break;
			ans=max(ans,cs);
			int tui=(n-i)*a;
			int yod=t-tui-sp;
			int lch=0,rch=i,mch;
			while(rch-lch>1)
			{
				mch=(lch+rch)/2;
				if(qzh[mch]<=yod)lch=mch;
				else rch=mch;
			}
			ans=max(ans,lch+cs);
			sp+=a;
		}
		reverse(v,v+n+1);
	}
	printf("%d",ans);
	return 0;
}