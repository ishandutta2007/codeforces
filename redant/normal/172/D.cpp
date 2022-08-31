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

#define MX 10000007

int a, n;
int ans[MX];

int main()
{
    a = SI; n = SI;
    int b = a + n - 1;
    for(int i=1;i<=b;i++) ans[i] = i;
    for(int i=2;i*i<=b;i++)
        for(int k=i*i,j=k,p=1;j<=b;j+=k,p++)
            ans[j] = min(ans[j],p);
    long long r = 0;
    for(int i=a;i<=b;i++) r += ans[i];
    cout<<r<<endl;
    return 0;
}