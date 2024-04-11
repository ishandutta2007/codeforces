#pragma comment(linker, "/STACK:32777216")
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
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;

map<pair<ll,ll>,int> a[1000005];
vector<pair<ll,ll> > b[1000005];

ll gcd(ll a,ll b){
    if (b == 0) return a;
    return gcd(b,a%b);
}

ll labs(ll a){
    if (a>0) return a;
    else return -a;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    ll x[255];
    ll y[255];
    FOR(i,0,m){
        cin >> x[i] >> y[i];
    }
    FOR(i,0,m-1)
        FOR(j,i+1,m)
            if (y[i] != y[j])
                if ((x[i] * y[j] - x[j] * y[i]) % (y[j]-y[i]) == 0){
                    ll k = (x[i] * y[j] - x[j] * y[i]) / (y[j]-y[i]);
                    if (k>=1 && k<=n){
                        ll aa = y[i];
                        ll bb = x[i] - k;
                        ll g = gcd(labs(aa),labs(bb));
                        aa/=g;
                        bb/=g;
                        if (a[k][MP(aa,bb)] == 0){
                            b[k].PB(MP(aa,bb));
                            a[k][MP(aa,bb)] = 1;
                        }
                        else a[k][MP(aa,bb)]++;
                    }
    }

    int res = 0;
    FOR(i,1,n+1){
        int M = 0;
        FOR(j,0,b[i].size())
            M = max(M,a[i][b[i][j]]);
        res += (1 + int(sqrt(1.0+8.0*M)))/2;
    }
    cout << res;
    return 0;
}