// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[100010];
int main()
{
    gets(s);
    int n=0;
    for ( int i=0; s[i]; i++ ) {
        while ( n>0 && s[i]>s[n-1] ) n--;
        s[n++]=s[i];
    }
    s[n]=0;
    puts(s);
    return 0;
}