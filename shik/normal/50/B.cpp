// by shik
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define N 100010
using namespace std;
char s[N];
long long app[130];
int main()
{
    int n,i; long long ans=0;
    n=strlen(gets(s));
    for ( i=0; i<n; i++ ) app[(int)s[i]]++;
    for ( i=0; i<130; i++ ) ans+=app[i]*app[i];
    cout<<ans<<endl;
    return 0;
}