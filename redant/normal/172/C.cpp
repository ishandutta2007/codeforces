/*AnilKishore*India*/

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
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005

int n, m;
int ans[MX];
pair<int,PI> students[MX];

int main()
{
    n = SI; m = SI;
    REP(i,n)
    {
        students[i].F = SI;
        students[i].S.F = SI;
        students[i].S.S = i;
    }
    sort(students,students+n);
    int time = 0;
    for(int i=0;i<n;)
    {
        vector<PI> studs;
        for(int left=m;left>0 && i<n;left--,i++) studs.PB(students[i].S);
        time = max(time,students[i-1].F);
        SORT(studs);
        for(int x=0,k=0;k<SZ(studs);)
        {
            time += studs[k].F - x;
            x = studs[k].F;
            int cnt = 0;
            while(k<SZ(studs) && studs[k].F==x){ cnt++; ans[studs[k++].S] = time; }
            time += 1 + cnt/2;
            if(k==SZ(studs)) time += x;
        }
    }   
    REP(i,n) printf("%d ",ans[i]);
    puts("");
    return 0;
}