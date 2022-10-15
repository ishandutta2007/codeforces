// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng(1234);

const int mod=1e9+7;

int n,m,k,r,c;
int ax,ay,bx,by;

int modpow(int u,int v){
    int res=1, t=u;
    while (v){
        if (v&1) res=res*t%mod;
        t=t*t%mod, v>>=1;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15);
    cin>>n>>m>>k>>r>>c;
    cin>>ax>>ay>>bx>>by;
    if (ax==bx&&ay==by){
        cout<<modpow(k,n*m);
        return 0;
    }
    int comp=n*m-r*c;
    cout<<modpow(k,comp);
    return 0;
}