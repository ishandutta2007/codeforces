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
    int a[3][3]={};
    for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) scanf("%d",a[i]+j);
    int s[3]={};
    for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) s[i]+=a[i][j];
    int t=*max_element(s,s+3)+1;
    while ( 3*t-s[0]-s[1]-s[2]!=t ) t++;
    for ( int i=0; i<3; i++ ) a[i][i]=t-s[i];
    for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) printf("%d%c",a[i][j],j==2?'\n':' ');
    return 0;
}