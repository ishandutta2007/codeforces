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
#define INF 1e16
#define Mod 1e16
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

int n,m;
vector<pair<int,int> > lnj[100007];
INT pa[100007],dao[100007];
vector<int> luj;

int main()
{
	scanf("%d%d",&n,&m);
	int a,b,w;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		lnj[a-1].push_back(mp(b-1,w));
		lnj[b-1].push_back(mp(a-1,w));
	}
	fill(pa,pa+n,INF);
	pa[0]=0;
	fill(dao,dao+n,-1);
	set<pair<int,int> > s;
	s.insert(mp(0,0));
	while(!s.empty())
	{
		int se=s.begin()->second;
		s.erase(s.begin());
		for(int i=0;i<SZ(lnj[se]);i++)
		{
			int t=lnj[se][i].first,d=lnj[se][i].second;
			if(pa[t]>pa[se]+d)
			{
				s.erase(mp(pa[t],t));
				pa[t]=pa[se]+d;
				dao[t]=se;
				s.insert(mp(pa[t],t));
			}
		}
	}
	if(pa[n-1]==INF)OVER("-1");
	for(int i=n-1;i!=0;i=dao[i])
		luj.push_back(i+1);
	luj.push_back(1);
	reverse(luj.begin(),luj.end());
	for(int i=0;i<SZ(luj);i++)
		printf("%d%c",luj[i],i==SZ(luj)-1?'\n':' ');
	return 0;
}