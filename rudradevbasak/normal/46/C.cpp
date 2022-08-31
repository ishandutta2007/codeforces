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
char str[1111];
int n;

void solve()
{
    int cnt=0;
    int i,j;
    int curr,min=10000;
    for(i=0;i<n;i++)
        if(str[i]=='T')
            cnt++;
    for(i=0;i<n;i++)
    {
        curr=0;
        for(j=i;j<i+cnt;j++)
        {
            if(str[j%n]=='H')
                curr++;
        }
        if(curr<min)
            min=curr;
    }
    printf("%d\n",min);
}

void input()
{
    s(n);
    scanf("%s",str);
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