// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 110
char s[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    if ( n==5 ) {
        puts(">...v");
        puts("v.<..");
        puts("..^..");
        puts(">....");
        puts("..^.<");
        puts("1 1");
    } else if ( n==3 ) {
        puts(">vv");
        puts("^<.");
        puts("^.<");
        puts("1 3");
    } else {
        s[0][0]='>';
        for ( int i=0; i<100; i++ ) {
            if ( i%2==0 ) {
                for ( int j=1; j<50; j++ ) s[i][j]='>';
                for ( int j=50; j<98; j++ ) {
                    s[i][j]='.';
                    j++;
                    s[i][j]='>';
                }
                s[i][98]='.';
                s[i][99]='v';
            } else {
                for ( int j=99; j>50; j-- ) s[i][j]='<';
                for ( int j=50; j>2; j-- ) {
                    s[i][j]='.';
                    j--;
                    s[i][j]='<';
                }
                s[i][2]='.';
                s[i][1]='v';
            }
        }
        s[99][1]='<';
        for ( int i=99; i>0; i-- ) s[i][0]='^';
        for ( int i=0; i<100; i++ ) puts(s[i]);
        puts("1 1");
    }
    return 0;
}