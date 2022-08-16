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
int n,m;
int b[100005];
string names[100005];
int pts[100005];
string name;

typedef pair<int,string> team;
vector<team> arr;



void preprocess()
{

}

int position(vector<int> p,string name,int mypts)
{
	int ans=1;
	for(int i=0;i<n;i++)
	{
		if(p[i]>mypts || (p[i]==mypts && names[i].compare(name)<0) )
			ans++;
	}
	
	return ans;
}

void solve()
{
	sort(arr.begin(),arr.end());
	int index=-1;
	for(int i=0;i<n;i++)
	{
		names[i]=(arr[i].second);
		pts[i]=-arr[i].first;
		
		if( names[i].compare(name)==0)
		{
			index=i;
		}
	}
	//for(int i=0;i<n;i++)
	//	printf("%s  : %d\n",names[i].c_str(),pts[i]);
	//printf("\n");
		
	sort(b,b+m);
	
	
	vector<int> a;
	a.resize(n);
	for(int i=0;i<n;i++) a[i]=pts[i];
	a[index]+=b[m-1];
	int pos=m-2;
	
	for(int i=0;i<index && pos>=0;i++)
	{
		if(a[i] > a[index] || (a[i]==a[index] && names[i].compare(name)<0))
		{
			a[i]+=b[pos--];
		}
	}
	

	for(int i=n-1;i>=0 && pos>=0; i--)
	{
		if(i==index) continue;
		a[i] += b[pos--];
	}
	//for(int i=0;i<n;i++)
	//	printf("%s  : %d\n",names[i].c_str(),a[i]);
	//printf("\n");
		
	int hi=position(a,name,a[index]);
	
	a.clear();
	a.resize(n);
	for(int i=0;i<n;i++) a[i]=pts[i];
	int beg=0;
	int end=m-1;
	if(m==n)
	{	
		a[index]+=b[0];
		beg++;
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==index) continue;
		if( a[i] > a[index] || (a[i]==a[index] && names[i].compare(name)<0)) continue;
		
		if(names[i].compare(name)<0)
		{
			while(beg<m && a[i]+b[beg]<a[index])
				beg++;
			if(beg==m) break;
			a[i]+=b[beg++];
		}
		else
		{
			while(beg<m && a[i]+b[beg]<=a[index])
				beg++;
			if(beg==m) break;
			a[i]+=b[beg++];
		}	
	}
	//for(int i=0;i<n;i++)
	//	printf("%s  : %d\n",names[i].c_str(),a[i]);
	//printf("\n");
	
	int lo=position(a,name,a[index]);
	
	printf("%d %d\n",hi,lo);
}

bool input()
{
	s(n);
	arr.clear();
	char nm[25];
	for(int i=0;i<n;i++)
	{
		scanf("%s",nm);
		s(pts[i]);
		arr.pb(mp(-pts[i],string(nm)));
	}
	
	s(m);
	for(int i=0;i<m;i++)
		s(b[i]);
		
	scanf("%s",nm);
	name=string(nm);
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