// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
char s[110];
set<PII> vis;
int main()
{
    int x,y,dx=0,dy=0;
    scanf("%d%d%s",&x,&y,s);
    vis.insert(PII(0,0));
    for ( int i=0; s[i]; i++ ) {
        if ( s[i]=='U' ) dy++;
        else if ( s[i]=='D' ) dy--;
        else if ( s[i]=='L' ) dx--;
        else dx++;
        vis.insert(PII(dx,dy));
    }
    FOR(it,vis) {
        int xx=it->first;
        int yy=it->second;
        int dxx=x-xx;
        int dyy=y-yy;
        if ( dxx==0 && dyy==0 ) goto YES;
        else if ( dxx==0 ) {
            if ( dx==0 && dy!=0 && dyy%dy==0 && dyy/dy>0 ) goto YES;
        } else if ( dyy==0 ) {
            if ( dy==0 && dx!=0 && dxx%dx==0 && dxx/dx>0 ) goto YES;
        } else {
            if ( dy!=0 && dyy%dy==0 && dyy/dy>0 &&
                 dx!=0 && dxx%dx==0 && dxx/dx>0 && dxx/dx==dyy/dy ) goto YES;
        }
    }
    puts("No");
    return 0;
YES:
    puts("Yes");
    return 0;
}