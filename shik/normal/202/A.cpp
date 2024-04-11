// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[20],t[20],ans[20];
void go( int p, int lv ) {
    if ( !s[p] ) {
        for ( int i=0; i<lv; i++ ) if ( t[i]!=t[lv-i-1] ) return;
        t[lv]=0;
        if ( strcmp(t,ans)>0 ) strcpy(ans,t);
        return;
    }
    go(p+1,lv);
    t[lv]=s[p];
    go(p+1,lv+1);
}
int main()
{
    gets(s);
    go(0,0);
    puts(ans);
    return 0;
}