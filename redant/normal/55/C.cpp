/*
ID: AnilKishore ( RedAnt )
CONTEST: CodeForces#51
*/

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

#define MX 111

int main()
{
        bool win = false;
        
        int R=SI, C=SI, k=SI, x, y;
        
        while(k--)
        {
                x=SI; y=SI;
                if((x-1)<5||(y-1)<5||(R-x)<5||(C-y)<5) win=true;
        }

        printf(win ?"YES\n":"NO\n");

        return 0;
}