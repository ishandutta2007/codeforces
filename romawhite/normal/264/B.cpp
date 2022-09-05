//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <time.h>
#include <sstream>
using namespace std;

#define next gdfsgvd
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define FILL(a,value) memset(a,value,sizeof(a))

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const int INF=1000000007;
const LL mod= 1000000007;
const double EPS=1e-7;

int dp[100007];
int p[100007];
bool q = 0;

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);

    p[1] = 1;
    for(int i = 2; i *i <= 100005; ++i)
        if (!p[i])
            for(int j = i * i ; j <= 100005; j += i)
                if (!p[j])
                    p[j] = i;

    FOR(i,0,100005)
        if (!p[i])
            p[i] = i;

    int n;
    cin >> n;

    vector<int> pr;

    FOR(i,0,n){
        int a;
        cin >> a;
        if (a == 1) q = 1;
        pr.clear();
        while (a != 1){
            int P = p[a];
            pr.PB(P);
            while (a % P == 0) a /= P;
        }

        int M = 0;
        FOR(i,0,pr.size())
            M = max(M , dp[pr[i]] + 1);

        FOR(i,0,pr.size())
            dp[pr[i]] = M;

    }

    int res = 0;
    FOR(i,0,100007)
        res = max(res , dp[i]);
    if (!res && q) res = 1;
    cout << res << endl;

    return 0;
}