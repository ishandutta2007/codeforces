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
const int N=100*1000+322;
const int P=1336337;
/*----------------------------------*/
ll pw(ll a,int x){
    if(!x)
        return 1;
    if(x%2)
        return a*pw(a*a,x/2);
    return pw(a*a,x/2);
}

int gcd(int a,int b){
    if(b)
        return gcd(b,a%b);
    return a;
}
/*----------------------------------*/

unordered_map<ll,int> same_hash;
vector<unordered_map<int,int> > cnt(10*N);// type -> sch ---> cnt

ll fct[N*10];
ll pwr[N];
int n,m;

void prec(){
    fct[0]=1;
    pwr[0]=1;
    for(int i=1;i<10*N;++i){
        fct[i]=(fct[i-1]*i)%MOD;
        if(i<N)
            pwr[i]=pwr[i-1]*P;
    }
}

void hash_type(int tp){
    ll hash_=0;
    for(auto &i:cnt[tp]){
        hash_ += pwr[i.first]*i.second;
    }
    ++same_hash[hash_];
}

void solve(ld tt){
    prec();
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int poke=5;
        cin>>poke;
        for(int j=0;j<poke;++j){
            int typp;
            cin>>typp;
            ++cnt[typp][i];
        }
    }
    for(int i=1;i<=m;++i){
        hash_type(i);
    }
    ll res=1;
    for(auto &i:same_hash){
        res *= fct[i.second];
        res %= MOD;
    }
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