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
int cnt[N];

void gt(int x){
    for(int d=2;d*d<=x;++d){
        if(x%d)
            continue;
        else{
            ++cnt[d];
            while(!(x%d))
                x/=d;
        }
    }
    ++cnt[x];
}

void solve(ld tt){
    int n;
    cin>>n;
    int pwr[n];
    for(int i=0;i<n;++i)
        cin>>pwr[i];
    for(int i=0;i<n;++i)
        gt(pwr[i]);
    int mx=1;
    for(int i=2;i<N;++i){
        mx=max(mx,cnt[i]);
    }
    cout<<mx<<endl;
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