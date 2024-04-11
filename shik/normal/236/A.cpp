// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    char s[200];
    int n=strlen(gets(s));
    sort(s,s+n);
    n=unique(s,s+n)-s;
    puts(n%2==0?"CHAT WITH HER!":"IGNORE HIM!");
    return 0;
}