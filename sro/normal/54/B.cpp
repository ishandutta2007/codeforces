/**********************************************************
 * zxf
 * 2017/8/9
 * Cutting Jigsaw Puzzle
 * 54B
 * 
 * 
 * Time used
 * Memory used
 **********************************************************/
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

int x,y;
char pu[100][100];
vector<int> inshux,inshuy;
set<string> yod;
int cnt=0,minx=10000,miny=10000;

int main()
{
	scanf("%d%d",&x,&y);
	for(int i=0;i<x;i++)
		scanf("%s",pu[i]);
	for(int i=1;i<=x;i++)
		if(x%i==0)
			inshux.push_back(i);
	for(int i=1;i<=y;i++)
		if(y%i==0)
			inshuy.push_back(i);
	for(int i=0;i<SZ(inshux);i++)
		for(int j=0;j<SZ(inshuy);j++)
		{
			int a=inshux[i],b=inshuy[j];
			yod.clear();
			string s,s2;
			bool ended=0;
			for(int i=0;i<x&&!ended;i+=a)
				for(int j=0;j<y;j+=b)
				{
					for(int k=0;k<a;k++)
					{
						for(int l=0;l<b;l++)
							s+=pu[i+k][j+l];
						s+='\n';
					}
					for(int l=b-1;l>=0;l--)
					{
						for(int k=0;k<a;k++)
							s2+=pu[i+k][j+l];
						s2+='\n';
					}
					s=min(s,s2);
					s2="";
					for(int l=0;l<b;l++)
					{
						for(int k=a-1;k>=0;k--)
							s2+=pu[i+k][j+l];
						s2+='\n';
					}
					s=min(s,s2);
					s2="";
					for(int k=a-1;k>=0;k--)
					{
						for(int l=b-1;l>=0;l--)
							s2+=pu[i+k][j+l];
						s2+='\n';
					}
					s=min(s,s2);
					s2="";
					if(yod.count(s)){ended=1;break;}
					yod.insert(s);
					s="";
				}
			if(!ended)
			{
				cnt++;
				if(a*b<minx*miny)minx=a,miny=b;
			}
		}
	printf("%d\n%d %d\n",cnt,minx,miny);
	return 0;
}