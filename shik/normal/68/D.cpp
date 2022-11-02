// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#define LID (id*2+0)
#define RID (id*2+1)
using namespace std;
int h;
map<int,int> dp,val;
double go( int id, int lv, int tmt ) {
    if ( dp[id]<=tmt ) return pow(2.0,h-lv)*tmt;
    if ( lv==h ) return val[id];
    return go(LID,lv+1,max(tmt,val[id]+dp[RID]))+go(RID,lv+1,max(tmt,val[id]+dp[LID]));
}
int main()
{
    int q,x,y; char op[10];
    scanf("%d%d",&h,&q);
    while ( q-- ) {
        scanf("%s",op);
        if ( op[0]=='a' ) {
            scanf("%d%d",&x,&y);
            val[x]+=y;
            while ( x ) {
                dp[x]+=y;
                x>>=1;  
            }   
        } else printf("%.9f\n",go(1,0,0)/(1<<h));
    }
    return 0;
}