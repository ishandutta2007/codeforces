/*

short-32768~32767
unsigned short0~65535
int-2147483648~2147483647
uint0~4294967295
INT-9223372036854775808~9223372036854775807
UINT0~18446744073709551615
float-3.4e38~3.4e386~7
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
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <nul>
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
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;

int n,m;
bool a[5010][5010];
int k;
bool nsushu[2507];

inline void init()
{
	nsushu[0]=nsushu[1]=1;
	for(int i=2;i<2507;i++)
		if(!nsushu[i])
		{
			for(int j=i*i;j<2507;j+=i)
				nsushu[j]=1;
		}
}

int minn=Inf;

int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&a[i][j]);
	for(int aa=2;aa*aa<=max(n,m)+1;aa++)
		if(!nsushu[aa])
		{
			int cno=0,cni=0,cnt=0;
			for(int i=0;i<n;i+=aa)
				for(int j=0;j<m;j+=aa)
				{
					cno=cni=0;
					for(int ii=0;ii<aa;ii++)
						for(int jj=0;jj<aa;jj++)
							if(a[i+ii][j+jj])cni++;
							else cno++;
					cnt+=min(cno,cni);
				}
			minn=min(minn,cnt);
		}
	printf("%d\n",minn);
	return 0;
}