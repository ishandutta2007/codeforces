//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;

vector<LL> all;



void preprocess(LL num)
{
	if(num <= 1000000000ll) 
	{
		if(num>0)
			all.pb(num);
		preprocess(num*10+4);
		preprocess(num*10+7);
	}
}

LL al,ah,bl,bh,k;

void solve()
{
	int N=all.size();
	double sum=0;
	
	for(int i=0;i+k<=N;i++)
	{
		LL x = all[i];
		LL y = all[i+k-1];
		
		
		LL px,py;
		
		if(al<=x && bh>=y)
		{
			if(i==0)
				px = al;
			else
				px = max(al,all[i-1]+1);
			
			if(i+k==N)
				py = bh;
			else
				py = min(bh,all[i+k]-1);
				
			double t1 = min(x,ah)-px+1;
			double t2 = py-max(y,bl)+1;
			if(t1<0) t1=0;
			if(t2<0) t2=0;
			sum += t1*t2;
			//cout<<"up : "<<sum<<endl;
			//cout<<px<<" "<<py<<endl;
		}
		
		if(bl<=x && ah>=y)
		{
			if(i==0)
				py = bl;
			else
				py = max(bl,all[i-1]+1);
			
			if(i+k==N)
				px = ah;
			else
				px = min(ah,all[i+k]-1);
				
			double t1 = px-max(y,al)+1;
			double t2 = min(x,bh)-py+1;
			if(t1<0) t1=0;
			if(t2<0) t2=0;
			sum += t1*t2;
			//cout<<"down : "<<sum<<endl;
			//cout<<px<<" "<<py<<endl;
		}
		
		if(k==1 && al<=x && x<=ah && bl<=x && x<=bh) sum -= 1.0;
	}
	
	double tot = (double)(ah-al+1)*(double)(bh-bl+1);
	
	printf("%.12lf\n",sum/tot);
			
	
}

bool input()
{
	cin>>al>>ah>>bl>>bh>>k;
	return true;
}


int main()
{
	preprocess(0);
	
	sort(all.begin(),all.end());
	
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}