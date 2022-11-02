// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 2000010
char s1[N],s2[N];
vector<int> t1,t2;
int main()
{
    int n,c[2][2]={};
    scanf("%d%s%s",&n,s1,s2);
    for ( int i=0; i<2*n; i++ ) c[s1[i]-'0'][s2[i]-'0']++;
    for ( int i=0; i<n; i++ ) {
        if ( c[1][1]>0 ) c[1][1]--,t1.push_back(1);
        else if ( c[1][0]>0 ) c[1][0]--,t1.push_back(1);
        else if ( c[0][1]>0 ) c[0][1]--,t1.push_back(0);
        else if ( c[0][0]>0 ) c[0][0]--,t1.push_back(0);
        if ( c[1][1]>0 ) c[1][1]--,t2.push_back(1);
        else if ( c[0][1]>0 ) c[0][1]--,t2.push_back(1);
        else if ( c[1][0]>0 ) c[1][0]--,t2.push_back(0);
        else if ( c[0][0]>0 ) c[0][0]--,t2.push_back(0);
    }
    if ( t1>t2 ) puts("First");
    else if ( t1<t2 ) puts("Second");
    else puts("Draw");
    return 0;
}