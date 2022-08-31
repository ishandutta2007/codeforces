#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100010

int x,y;

int f(int p)
{
    if(p==0)
    {
        for(int i=2;i>=0;i--)
        {
            if(x>=i && i*100+y*10>=220)
            {
                x-=i; y-=(220-i*100)/10;
                return f(p^1);
            }
        }
        
        return p;
    }
    else
    {
        for(int i=0;i<=2;i++)
        {
            if(x>=i && i*100+y*10>=220)
            {
                x-=i; y-=(220-i*100)/10;
                return f(p^1);
            }
        }
        
        return p;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in1.in","r",stdin);
    #endif
    
    x = SI, y = SI;
    
    puts( f(0) ? "Ciel" : "Hanako" );
    
    
    return 0;
}