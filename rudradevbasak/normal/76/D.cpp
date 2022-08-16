//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>


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
typedef unsigned long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
LL A,B,X,Y;


void preprocess()
{

}

void solve()
{

}

void input()
{

}


int main()
{
	cin>>A>>B;
	X=(A-B)/2;
	if(X>A || B>A || (A-B)%2)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	Y=A-X;
	if(X^Y == B)
		cout<<X<<" "<<Y<<endl;
	else
		cout<<"-1"<<endl;
}