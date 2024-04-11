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
#define Inf 1e16
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=1;i<=x;i++)
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

INT n,m,x,y;
INT u,v,w,t[1007],c[1007];
vector<pair<INT,INT> > nei[1007],gonei[1007];
set<pair<INT,INT> > ww1,ww2;
INT duan[1007],duan2[1007];

int main()
{
	//
	cin>>n>>m>>x>>y;
	FOR(i,m)
	{
		cin>>u>>v>>w;
		nei[u].push_back(mp(v,w));
		nei[v].push_back(mp(u,w));
	}
	INT wid,dx,dy;
	FOR(i,n)
	{
		cin>>t[i]>>c[i];
	}
	FOR(i,n)
	{
		fill(duan,duan+1007,Inf);
		ww1.clear();
		ww1.insert(mp(0,i));
		duan[i]=0;
		while(!ww1.empty())
		{
			wid=ww1.begin()->second;
			ww1.erase(ww1.begin());
			for(int j=0;j<SZ(nei[wid]);j++)
			{
				dx=nei[wid][j].first,dy=nei[wid][j].second;
				if(duan[dx]>duan[wid]+dy)
				{
					ww1.erase(mp(duan[dx],dx));
					duan[dx]=duan[wid]+dy;
					ww1.insert(mp(duan[dx],dx));
				}
			}
		}
		FOR(j,n)if(duan[j]<=t[i])gonei[i].push_back(mp(j,c[i]));
	}
	//dijkstra
	fill(duan2,duan2+1007,Inf);
	ww2.insert(mp(0,x));
	duan2[x]=0;
	while(!ww2.empty())
	{
		wid=ww2.begin()->second;
		ww2.erase(ww2.begin());
		for(int j=0;j<SZ(gonei[wid]);j++)
		{
			dx=gonei[wid][j].first,dy=gonei[wid][j].second;
			if(duan2[dx]>duan2[wid]+dy)
			{
				ww2.erase(mp(duan2[dx],dx));
				duan2[dx]=duan2[wid]+dy;
				ww2.insert(mp(duan2[dx],dx));
			}
		}
	}
	cout<<(duan2[y]==Inf?-1:duan2[y])<<endl;
	return 0;
}