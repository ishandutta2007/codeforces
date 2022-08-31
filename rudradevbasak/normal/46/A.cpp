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


#define FOR(i,a,b)                          for(int i=a;i<b;i++)
#define REP(i,n)                            FOR(i,0,n)
#define pb                              push_back
#define s(n)                                scanf("%d",&n)
#define sl(n)                               scanf("%lld",&n)
#define sf(n)                               scanf("%lf",&n)
#define fill(a,v)                           memset(a, v, sizeof a)
#define sz                              size()
#define INF                             (int)1e9
#define EPS                             1e-9
#define bitcount                            __builtin_popcount
#define all(x)                              x.begin(), x.end()
#define gcd                             __gcd


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int n;

void solve()
{
    int curr=1;
    for(int i=1;i<n;i++)
    {
        curr+=i;
    while(curr>n)
        curr-=n;
        
        printf("%d ",curr);
    }
}

void input()
{
    s(n);
}


int main()
{
    
     int T=1; //s(T);
    while(T--)
    {
        input();
        solve();
    }
}