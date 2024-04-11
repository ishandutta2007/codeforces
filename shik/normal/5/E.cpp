// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

#define N 1000010

struct P {
    int val,cnt;
} stk[2*N];

int n,a[2*N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    REP(i,n) a[i+n]=a[i];
    int big=*max_element(a,a+n);
    LL ans=0,mid_ans=0;
    int top=0;
    REP(i,2*n) {
        if ( i==n ) mid_ans=ans;
        while ( top>0 && stk[top-1].val<a[i] ) {
            ans+=stk[top-1].cnt;
            top--;
        }
        if ( top>0 ) {
            if ( stk[top-1].val==a[i] ) {
                if ( a[i]==big ) {
                    top=0;
                    stk[top++]=P{a[i],1};
                } else {
                    ans+=stk[top-1].cnt;
                    if ( top>=2 ) ans++;
                    stk[top-1].cnt++;
                }
            } else {
                ans++;
                stk[top++]=P{a[i],1};
            }
        } else {
            stk[top++]=P{a[i],1};
        }
    }
    ans-=mid_ans;
    int cnt_big=count(a,a+n,big);
    if ( cnt_big==1 ) {
        int big2=0;
        REP(i,n) if ( a[i]>big2 && a[i]<big ) big2=a[i];
        ans-=count(a,a+n,big2);
    } else {
        ans+=1LL*cnt_big*(cnt_big-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}