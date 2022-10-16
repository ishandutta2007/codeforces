#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false);
#define coutdouble cout<<setprecision(20);cout<<fixed;
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int INF=1000LL*1000LL*1000LL;
const ll LLINF=1000LL*1000LL*1000LL*1000LL*1000LL*1000LL;
const int MOD=1000*1000*1000+7;
const int RMOD=1000*1000*1000+5;
const int N=1000*1000+322;
const int P=1336337;//Large prime number
/*----------------------------------*/
inline ll pw(ll x,ll pow){
    ll mlt=1;
    while(pow){
        if(pow&1){
            mlt *= x;
            x *= x;
            pow >>= 1;
            x %= MOD;
            mlt %= MOD;
        }else{
            pow >>= 1;
            x *= x;
            x %= MOD;
        }
    }
    return mlt;
}

int gcd(int a,int b){
    if(b)
        return gcd(b,a%b);
    return a;
}

inline ll rev(ll r){
    return pw(r,RMOD);
}
/*----------------------------------*/
int dist(int a,int b){
    return min(abs(b-a),10-abs(b-a));
}

vector<int> cur;
vector<int> want;

void solve(ld tt){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        char e;
        cin>>e;
        cur.pb((int)e );
    }
    for(int i=0;i<n;++i){
        char e;
        cin>>e;
        want.pb((int)e );
    }
    int res=0;
    for(int i=0;i<n;++i)
        res+=dist(cur[i],want[i]);
    cout<<res<<endl;
}




int main(){
    ld tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #else
//        freopen("","r",stdin);
//        freopen("","w",stdout);
    #endif // LOCAL

    speedup
//    coutdouble

    solve(tt);

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL

    return 0;
}