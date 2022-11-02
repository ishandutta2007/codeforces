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

#define N 4010
char s[N];
int main() {
    int a;
    scanf("%d%s",&a,s);
    if ( a==0 ) {
        LL cnt=0;
        for ( int i=0; s[i]; i++ ) {
            int now=0;
            for ( int j=i; s[j]; j++ ) {
                now+=s[j]-'0';
                if ( now==0 ) cnt++;
            }
        }
        int len=strlen(s);
        LL shik=len*(len+1)/2;
        LL ans=2*cnt*shik-cnt*cnt;
        cout << ans << endl;
        return 0;
    }
    map<int,int> app;
    for ( int i=0; s[i]; i++ ) {
        int now=0;
        for ( int j=i; s[j]; j++ ) {
            now+=s[j]-'0';
            if ( now && a%now==0 ) app[now]++;
        }
    }
    LL ans=0;
    FOR(it,app) {
        int x=it->first;
        int y=a/x;
        int cx=it->second;
        int cy=app[y];
        ans+=1LL*cx*cy;
    }
    cout << ans << endl;
    return 0;
}