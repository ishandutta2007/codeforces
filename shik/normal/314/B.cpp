// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
#define N 210
char a[N],c[N];
int b,d;
PLI na[30][N];
int main()
{
    scanf("%d%d%s%s",&b,&d,a,c);
    int n=strlen(a);
    int m=strlen(c);
    for ( int i=0; i<n; i++ ) {
        LL t1=0;
        int t2=i;
        for ( int j=0; j<m; j++ ) {
            int tt=t2;
            while ( t2<n && a[t2]!=c[j] ) t2++;
            if ( t2==n ) {
                t1++;
                t2=0;
                while ( t2<tt && a[t2]!=c[j] ) t2++;
                if ( t2==tt ) {
                    puts("0");
                    return 0;
                }
            }
            t2++;
            if ( t2==n ) {
                t1++;
                t2=0;
            }
        }
        na[0][i]=PLI(t1,t2);
    }
    for ( int i=0; i+1<30; i++ ) {
        for ( int j=0; j<n; j++ ) {
            PLI p1=na[i][j];
            PLI p2=na[i][p1.second];
            na[i+1][j]=PLI(p1.first+p2.first,p2.second);
        }
    }
    LL cnt=0;
    int pos=0,ans=0;
    for ( int i=29; i>=0; i-- ) {
        if ( cnt+na[i][pos].first>b || (cnt+na[i][pos].first==b && na[i][pos].second>0) ) continue;
        ans+=1<<i;
        cnt+=na[i][pos].first;
        pos=na[i][pos].second;
    }
    ans/=d;
    printf("%d\n",ans);
    return 0;
}