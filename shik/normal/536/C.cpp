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

#define N 200010
int n,s[N],r[N],ss[N],stk[N],top;

PII get( int i ) {
    return MP(s[i],r[i]);
}

bool cmp( int a, int b ) {
    return get(a)>get(b);
}

int main() {
    RI(n);
    REP(i,n) RI(s[i],r[i]);
    REP(i,n) ss[i]=i;
    sort(ss,ss+n,cmp);
    REP(ii,n) {
        int i=ss[ii];
        if ( ii>0 && get(i)==get(ss[ii-1]) ) continue;
#define x1 stk[top-1]
#define x2 stk[top-2]
        while ( top>=2 ) {
            LL s1=s[i],r1=r[i];
            LL s2=s[x1],r2=r[x1];
            LL s3=s[x2],r3=r[x2];
            if ( r1<=r2 ) break;
            LL u1=(s2-s1)*r1,d1=(r1-r2)*s1;
            LL u2=(s3-s2)*r3,d2=(r2-r3)*s3;
            assert(u1>=0 && d1>0 && u2>=0 && d2>0);
            if ( u1*d2>=u2*d1 ) break;
            top--;
        }
        if ( top==0 || (top>0 && r[i]>r[x1]) ) stk[top++]=i;
    }
    set<PII> st;
    REP(i,top) st.insert(get(stk[i]));
    vector<int> sol;
    REP(i,n) if ( st.count(get(i)) ) sol.PB(i);
    REP(i,SZ(sol)) printf("%d%c",sol[i]+1,i+1==SZ(sol)?'\n':' ');
    return 0;
}