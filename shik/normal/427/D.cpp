// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 5010

void make( int n1, char s1[], int n2, char s2[], int dp[N][N] ) {
    for ( int i=n1-1; i>=0; i-- )
        for ( int j=n2-1; j>=0; j-- )
            if ( s1[i]==s2[j] ) dp[i][j]=dp[i+1][j+1]+1;
            else dp[i][j]=0;
}

int n1,n2,dp11[N][N],dp12[N][N],dp22[N][N],l1[N],l2[N];
char s1[N],s2[N];

int main() {
    n1=strlen(gets(s1));
    n2=strlen(gets(s2));
    make(n1,s1,n1,s1,dp11);
    make(n1,s1,n2,s2,dp12);
    make(n2,s2,n2,s2,dp22);
    REP(i,n1) REP(j,n1) if ( i!=j ) l1[i]=max(l1[i],dp11[i][j]);
    REP(i,n2) REP(j,n2) if ( i!=j ) l2[i]=max(l2[i],dp22[i][j]);
    int ans=N;
    REP(i,n1) REP(j,n2) if ( dp12[i][j]>l1[i] && dp12[i][j]>l2[j] ) ans=min(ans,max(l1[i],l2[j])+1);
    if ( ans==N ) puts("-1");
    else printf("%d\n",ans);
    return 0;
}