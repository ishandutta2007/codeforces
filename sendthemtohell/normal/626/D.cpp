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
const int INF = 1000*1000*1000;
const ll LLINF = 1000LL*1000LL*1000LL*1000LL*1000LL*1000LL;
const int MOD = 1000*1000*1000+7;
const int RMOD = MOD - 2;
const int N = 10000+322;
const int P1M = 1336337; //Large prime number ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld Pi = acos(-1);
/*----------------------------------*/
inline ll pwm(ll x,ll pow){
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

inline ll pw(ll x, int pow){
    ll mlt = 1;
    while( pow ){
        if( pow & 1 ){
            mlt *= x;
            x *= x;
            pow >>= 1;
        }else{
            pow >>= 1;
            x *= x;
        }
    }
    return mlt;

}

int gcd( int a, int b ){
    if( b )
        return gcd( b, a%b );
    return a;
}

inline ll rev( ll r ){
    return pwm( r, RMOD );
}
/*----------------------------------*/

void solve(ld tt){
    int *eq,*more;
    eq=(int *)calloc(N,sizeof(int));
    more=(int *)calloc(N,sizeof(int));
    eq+=5000;
    more+=5000;
    int n;
    cin>>n;
    int ball[N];
    for(int i=0;i<n;++i)
        cin>>ball[i];
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ++eq[ball[i]-ball[j]];
            ++eq[ball[j]-ball[i]];
        }
    }
    int kek=0;
    for(int i=5000;i>=-5000;--i){
        more[i]=kek;
        kek+=eq[i];
    }
/*    for(int i=-10;i<=10;++i)
        cout<<eq[i]<<"  ";
    cout<<endl;
    for(int i=-10;i<=10;++i)
        cout<<more[i]<<"  ";
    cout<<endl;
*/    ll var=0;
    for(int i=-5000;i<0;++i){
        for(int j=-5000;j<0;++j){
            if(-(i+j)<5000)
                var+=(ll)eq[i]*eq[j]*more[-(i+j)];
        }
    }
    ld prob=(ld)var/(ld)pw(n*(n-1)/2,3);
    cout<<prob<<endl;
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
    coutdouble

    solve(tt);

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL

    return 0;
}