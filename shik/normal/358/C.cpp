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
#define REP(i,n) for (int i=0; i<(n); i++)
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

void solve( VI &v ) {
    if ( SZ(v)==0 ) {
        puts("0");
    } else if ( SZ(v)==1 ) {
        puts("pushStack");
        puts("1 popStack");
    } else if ( SZ(v)==2 ) {
        puts("pushStack");
        puts("pushQueue");
        puts("2 popStack popQueue");
    } else {
        int a[3]={};
        FOR(it,v) {
            if ( *it>=a[0] ) {
                a[2]=a[1];
                a[1]=a[0];
                a[0]=*it;
            } else if ( *it>=a[1] ) {
                a[2]=a[1];
                a[1]=*it;
            } else if ( *it>=a[2] ) {
                a[2]=*it;
            }
        }
        FOR(it,v) {
            if ( *it==a[0] ) {
                a[0]=-1;
                puts("pushStack");
            } else if ( *it==a[1] ) {
                a[1]=-1;
                puts("pushQueue");
            } else if ( *it==a[2] ) {
                a[2]=-1;
                puts("pushFront");
            } else {
                puts("pushBack");
            }
        }
        puts("3 popStack popQueue popFront");
    }
    v.clear();
}

#define N 100010
int n,op[N];
int main() {
    RI(n);
    REP(i,n) RI(op[i]);
    vector<int> v;
    REP(i,n) {
        if ( op[i]==0 ) solve(v);
        else v.PB(op[i]);
    }
    REP(i,SZ(v)) puts("pushStack");
    return 0;
}