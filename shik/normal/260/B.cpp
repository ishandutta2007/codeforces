// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check( char *s ) {
    if ( s[2]!='-' || s[5]!='-' ) return 0;
    for ( int i=0; i<10; i++ ) if ( i!=2 && i!=5 && !isdigit(s[i]) ) return 0;
    int d,m,y;
    sscanf(s,"%d-%d-%4d",&d,&m,&y);
    if ( y<2013 || y>2015 ) return 0;
    if ( m<1 || m>12 ) return 0;
    if ( d<1 || d>mon[m] ) return 0;
    return 1;
}
char s[100010];
map<string,int> cnt;
int main()
{
    gets(s);
    for ( int i=0; s[i]; i++ ) if ( check(s+i) ) cnt[string(s+i,s+i+10)]++;
    string ans;
    FOR(it,cnt) if ( it->second > cnt[ans] ) ans=it->first;
    printf("%s\n",ans.c_str());
    return 0;
}