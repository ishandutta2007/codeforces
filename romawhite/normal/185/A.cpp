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
const ll mod=1000000007;

ll bpow(ll n,ll k){
    if (k == 0) return 1;
    if (k%2 == 1) return (n* bpow(n,k-1)) % mod;
    return bpow((n*n)%mod,k/2);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n;
    cin >> n;
    if (!n){
        cout << 1;
        return 0;
    }
    ll res = (bpow(2ll,n-1) * (bpow(2ll,n)+1))%mod;
    cout << res;
    return 0;
}