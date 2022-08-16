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
int num[5];
int n;
int size[1111];
int pref[5][5]={{0,1,2,3,4},{1,2,0,3,4},{2,3,1,4,0},{3,4,2,1,0},{4,3,2,1,0}};
char ans[5][5]={"S","M","L","XL","XXL"};


void solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(num[pref[size[i]][j]]>0)
            {
                printf("%s\n",ans[pref[size[i]][j]]);
                num[pref[size[i]][j]]--;
                break;
            }
        }
    }
        
}

void input()
{
    char str[10];
    for(int i=0;i<5;i++)
        s(num[i]);
    s(n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        if(str[0]=='S')
            size[i]=0;
        else if(str[0]=='M')
            size[i]=1;
        else if(str[0]=='L')
            size[i]=2;
        else if(str[1]=='L')
            size[i]=3;
        else if(str[2]=='L')
            size[i]=4;
    }
}


int main()
{
    
    //int T=1; //s(T);
    //while(T--)
    {
        input();
        solve();
    }
}