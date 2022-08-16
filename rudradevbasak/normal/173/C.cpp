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
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
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
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
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
int arr[500][500];
int psum[501][501];

int get(int r1,int r2,int c1,int c2)
{
	r2++; c2++;
	return psum[r2][c2] - psum[r2][c1] - psum[r1][c2] + psum[r1][c1];
}

bool isok(int i,int j,int k)
{
	return (i-k>=0 && j-k>=0 && i+k<R && j+k<C);
}

void solve()
{
	int ans=-INF;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			int sum = arr[i][j];
			for(int k=2; true; k+=2)
			{
				if(!isok(i,j,k)) break;
				int prevk = k-2;
				sum += arr[i-prevk][j-prevk-1];
				sum += get(i-prevk,i+k,j-prevk-2,j-prevk-2);
				sum += get(i+k,i+k,j-prevk-1,j+k);
				sum += get(i-k,i+k-1,j+k,j+k);
				sum += get(i-k,i-k,j-k,j+k-1);
				ans=max(sum,ans);
			}
			
			if(isok(i,j,1))
			{
				sum = get(i-1,i+1,j-1,j+1) - arr[i][j] - arr[i][j-1];
				ans = max(sum,ans);
				
				for(int k=3; true; k+=2)
				{
					if(!isok(i,j,k)) break;
					int prevk = k-2;
					sum += arr[i-prevk][j-prevk-1];
					sum += get(i-prevk,i+k,j-prevk-2,j-prevk-2);
					sum += get(i+k,i+k,j-prevk-1,j+k);
					sum += get(i-k,i+k-1,j+k,j+k);
					sum += get(i-k,i-k,j-k,j+k-1);
					ans=max(sum,ans);
				}
			}
		}
	printf("%d\n",ans);
		
}

bool input()
{
	fill(psum,0);
	s(R); s(C);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			s(arr[i][j]);
			psum[i+1][j+1] = arr[i][j] + psum[i][j+1] + psum[i+1][j] - psum[i][j];
		}
		
	return true;
}


int main()
{
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}