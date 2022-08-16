#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				(a>b?a:b)
#define miN(a,b)				(a<b?a:b)
#define abS(x)					(x<0?-x:x)
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug1(a)				cout<<a<<endl
#define debug2(a,b)				cout<<a<<" "<<b<<endl
#define debug3(a,b,c)			cout<<a<<" "<<b<<" "<<c<<endl
#define debug4(a,b,c,d)			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

void debugvi(vector<int> arr,int n=INF){
	REP(i,min(SZ(arr),n)) printf("%d ",arr[i]);
	printf("\n");
}

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

/*Main code begins now */

int testnum;
char temp[100005];
int m,n;
int freq[2][15];


void preprocess()
{

}

void solve()
{
	int best=0;
	int bests=-1;
	int bestx=-1;
	
	for(int i=1;i<=9;i++)
	{
		int j=0;
		if(i>0) j=10-i;
		
		if(freq[0][i]==0 || freq[1][j]==0) continue;
		
		freq[0][i]--;
		freq[1][j]--;
		
		int cur=1;
		
		for(int j=0;j<=9;j++)
			cur += min(freq[0][j],freq[1][9-j]);
			
		int z=0;
		if(freq[0][0]>freq[1][9] && freq[1][0]>freq[0][9])
			z= min(freq[0][0]-freq[1][9], freq[1][0]-freq[0][9]);
		cur+=z;
			
		if(cur>best)
		{
			best=cur;
			bests=i;
			bestx=z;
		}
			
		freq[0][i]++;
		freq[1][j]++;
	}
	
	if(bests<0)
	{
		for(int k=0;k<2;k++)
		{
			for(int i=9;i>=0;i--)
				for(int j=0;j<freq[k][i];j++)
					printf("%c",(char)('0'+i));
			printf("\n");
		}
		return;
	}
	
	string a="",b="";
	
	for(int i=0;i<bestx;i++)
	{
		a+='0';
		b+='0';
		freq[0][0]--;
		freq[1][0]--;
	}
		
	
	int bestt = 0;
	if(bests>0) bestt=10-bests;
	
	
	a+=((char)('0'+bests));
	b+=((char)('0'+bestt));
	freq[0][bests]--;
	freq[1][bestt]--;
	
	//debug1(bests);
	
	for(int j=0;j<=9;j++)
	{
		int z=min(freq[0][j],freq[1][9-j]);
		//debug3(j,freq[0][j],freq[1][9-j]);
		for(int k=0;k<z;k++)
		{
			a+=((char)('0'+j));
			b+=((char)('0'+9-j));
		}
		freq[0][j]-=z;
		freq[1][9-j]-=z;
	}
	
	for(int k=0;k<2;k++)
	{
		for(int i=0;i<=9;i++)
			for(int j=0;j<freq[k][i];j++)
			{
				if(k==0)
					a+=((char)('0'+i));
				else
					b+=((char)('0'+i));
			}
	}
	
	reverse(all(a));
	reverse(all(b));
	
	printf("%s\n",a.c_str());
	printf("%s\n",b.c_str());
		
		
}

bool input()
{
	fill(freq,0);
	ss(temp); m=strlen(temp);
	REP(i,m)
		freq[0][temp[i]-'0']++;
	
	
	REP(i,10)
		freq[1][i]=freq[0][i];
	
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}