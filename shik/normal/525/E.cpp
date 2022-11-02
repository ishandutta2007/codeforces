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

struct P {
    int k;
    LL s;
};

inline bool operator <( const P &a, const P &b ) {
    return tie(a.s,a.k)<tie(b.s,b.k);
}

LL f[100];

void build( int n, int a[], int &m, P b[] ) {
    function<void(int,int,LL)> dfs=[&]( int p, int k, LL s ) {
        if ( p==n ) {
            b[m++]=P{k,s};
            return;
        }
        dfs(p+1,k,s);
        dfs(p+1,k,s+a[p]);
        if ( a[p]<=18 ) dfs(p+1,k+1,s+f[a[p]]);
    };
    dfs(0,0,0);
    sort(b,b+m);
}

#define N 25
#define M 1594323
int n,k,a[N];
LL s;
P b1[M],b2[M];

int main() {
    f[0]=1;
    REP1(i,1,20) f[i]=f[i-1]*i;
    cin>>n>>k>>s;
    REP(i,n) RI(a[i]);
    random_shuffle(a,a+n);
    
    if ( n==1 ) {
        int ans=0;
        if ( a[0]==s ) ans++;
        if ( k>0 && a[0]<=18 && f[a[0]]==s ) ans++;
        printf("%d\n",ans);
        return 0;
    }

    int n1=n/2;
    int n2=n-n/2;
    int m1=0,m2=0;
    build(n1,a,m1,b1);
    build(n2,a+n1,m2,b2);
    LL ans=0;
    int base=m2;
    for ( int i=0,j=m2-1; i<m1; i++ ) {
        while ( j>=0 && b1[i].s+b2[j].s>s ) j--;
        if ( j<0 || b1[i].s+b2[j].s!=s ) continue;
        while ( j>=0 && b1[i].s+b2[j].s==s && b1[i].k+b2[j].k>k ) j--;
        if ( j<0 || b1[i].s+b2[j].s!=s ) continue;
        if ( j<base ) {
            base=j;
            while ( base>=0 && b2[base].s==b2[j].s ) base--;
            base++;
        }
        ans+=j-base+1;
    }
    cout<<ans<<endl;
    return 0;
}