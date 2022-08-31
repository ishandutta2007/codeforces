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
#define debug1(a)				cout<<(a)<<endl
#define debug2(a,b)				cout<<(a)<<" "<<(b)<<endl
#define debug3(a,b,c)			cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define debug4(a,b,c,d)			cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define debug5(a,b,c,d,e)		cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl

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
int R,C;
char arr[50][50]; 
int dp[51][51][51][51];

char value;

bool inside(int a,int b)
{
	//if(a==0 || a==50 || b==0 || b==50) return false;
	b-=26;
	//if(a<b) return false;
	
	int r = (a-b)/2;
	int c = (a+b)/2;
	bool z = 1<=r && r<=R && 1<=c && c<=C;
	if(z)
		value = arr[r-1][c-1];
	return z;
}



int memo(int a1,int b1,int a2,int b2)
{
	if(a2-a1<=2 || b2-b1<=2) return 0;
	if(dp[a1][b1][a2][b2]>=0) return dp[a1][b1][a2][b2];
	
	bool used[64];
	fill(used,false);
	for(int i=a1+2;i<=a2-2;i+=2)
		for(int j=b1+2;j<=b2-2;j+=2)
		{
			if(!inside(i,j)) continue;
			
			if(value=='L')
			{
				int x1 = memo(a1,b1,i,b2);
				int x2 = memo(i,b1,a2,b2);
				used[x1^x2]=true;
			}
			else if(value=='R')
			{
				int x1 = memo(a1,b1,a2,j);
				int x2 = memo(a1,j,a2,b2);
				used[x1^x2]=true;
			}
			else
			{
				int x1 = memo(a1,b1,i,j);
				int x2 = memo(i,j,a2,b2);
				int x3 = memo(a1,j,i,b2);
				int x4 = memo(i,b1,a2,j);
				used[x1^x2^x3^x4]=true;
			}
		}
	

	for(int i=0; ;i++)
		if(!used[i])
		{
			dp[a1][b1][a2][b2]=i;
			return i;
		}
}
			
			

void preprocess()
{

}

void solve()
{
	fill(dp,-1);
	//debug1(inside(2,26));
	int x1 = memo(0,0,50,50);
	int x2 = memo(1,1,49,49);
	int x = x1^x2;
	//debug3(x1,x2,x1^x2);
	if(x==0)
		printf("LOSE\n");
	else
		printf("WIN\n");
}

bool input()
{
	s(R); s(C);
	for(int i=0;i<R;i++)
		ss(arr[i]);
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