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

char s[1520];
int n;
int q;
int a[1520];
int cnt[30],mx[30];
int nd[30][1520];

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	FOR(i,n)a[i]=s[i]-'a';
	FOR(i,30)
		FOR(j,1520)
			nd[i][j]=Inf;
	FOR(i,30)nd[i][0]=0;
	for(int len=1;len<=n;len++)
	{
		memset(cnt,0,sizeof(cnt));
		memset(mx,0,sizeof(mx));
		FOR(i,len)
		{
			cnt[a[i]]++;
			mx[a[i]]++;
		}
		for(int i=len;i<n;i++)
		{
			cnt[a[i-len]]--;
			cnt[a[i]]++;
			mx[a[i]]=max(mx[a[i]],cnt[a[i]]);
		}
		FOR(i,30)nd[i][len]=len-mx[i];
	}
	scanf("%d",&q);
	int num,nch,lch,rch,mch;
	char chr;
	while(q--)
	{
		scanf("%d %c",&num,&chr);
		nch=chr-'a';
		lch=0,rch=n+1;
		while(rch-lch>1)
		{
			mch=(lch+rch)/2;
			if(nd[nch][mch]<=num)lch=mch;
			else rch=mch;
		}
		printf("%d\n",lch);
	}
	return 0;
}