// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
unsigned read() {
    unsigned a,b,c,d;
    scanf("%u.%u.%u.%u",&a,&b,&c,&d);
    return (a<<24)|(b<<16)|(c<<8)|d;
}
void print( unsigned ip ) {
    unsigned char ch[4];
    *(int*)ch = ip;
    printf("%u.%u.%u.%u\n",ch[3],ch[2],ch[1],ch[0]);
}
#define N 100010
int n;
unsigned ip[N];
int get( unsigned msk ) {
    static int me[N];
    for ( int i=0; i<n; i++ ) me[i]=(ip[i]&msk);
    sort(me,me+n);
    return unique(me,me+n)-me;
}
int main()
{
    int k;
    scanf("%d%d",&n,&k);
    for ( int i=0; i<n; i++ ) ip[i]=read();
    for ( int i=31; i>=0; i-- ) {
        unsigned msk=~0<<i;
        int now=get(msk);
        if ( now==k ) {
            print(msk);
            return 0;
        }
    }
    puts("-1");
    return 0;
}