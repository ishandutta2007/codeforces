// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[1010];
int main()
{
    gets(s);
    int c[26]={};
    for ( int i=0; s[i]; i++ ) c[s[i]-'a']++;
    int d[2]={};
    for ( int i=0; i<26; i++ ) d[c[i]%2]++;
    if ( d[1]<=1 ) puts("First");
    else if ( d[1]%2==0 ) puts("Second");
    else puts("First");
    return 0;
}