// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

#define N 100010
int n,m,s;

struct Bug {
    int id,a;
} bug[N];

struct Stu {
    int id,b,c;
} stu[N];

int sol[N];
bool chk( int mid ) {
    auto cmp = []( Stu a, Stu b ) { return a.c > b.c; };
    priority_queue<Stu,vector<Stu>,decltype(cmp)> q(cmp);
    int bi=0,si=0,tot=0;
    while ( bi<m ) {
        while ( si<n && stu[si].b >= bug[bi].a ) {
            q.push(stu[si]);
            si++;
        }
        if ( q.empty() ) return 0;
        auto p=q.top(); q.pop();
        tot+=p.c;
        if ( tot>s ) return 0;
        REP(i,mid) {
            sol[bug[bi].id]=p.id;
            bi++;
            if ( bi>=m ) break;
        }
    }
    return 1;
}

int main() {
    RIII(n,m,s);
    REP(i,m) bug[i].id=i;
    REP(i,m) RI(bug[i].a);
    REP(i,n) stu[i].id=i;
    REP(i,n) RI(stu[i].b);
    REP(i,n) RI(stu[i].c);
    sort(bug,bug+m,[]( Bug a, Bug b ) { return a.a>b.a; });
    sort(stu,stu+n,[]( Stu a, Stu b ) { return a.b>b.b; });
    int l=1,r=m+1;
    while ( l!=r ) {
        int mid=(l+r)/2;
        if ( chk(mid) ) r=mid;
        else l=mid+1;
    }
    if ( l>m ) puts("NO");
    else {
        puts("YES");
        chk(l);
        REP(i,m) printf("%d%c",sol[i]+1,i+1==m?'\n':' ');
    }
    return 0;
}