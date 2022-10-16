#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair

const int N=3228;
const int MOD=1000*1000*1000+7;

ll more[N][N];

void precalc(){
    more[0][0]=1;
    for(int i=1;i<N;++i){
        for(int j=0;j<N;++j){
            if(j>0)
                more[i][j] += more[i-1][j-1];
            if(j<N-1)
                more[i][j] += more[i-1][j+1];
            more[i][j] %= MOD;
        }
    }
}

void solve(){
    precalc();
    int n,m;
    int minn=0,maxx=0,delta=0;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        char cur;
        cin>>cur;
        if(cur=='(')
            delta += 1;
        else
            delta -= 1;
        minn = min(minn,delta);
        maxx = max(maxx,delta);
    }
    minn *= -1;
   // cout<<minn<<"  "<<maxx<<endl;
  /*  for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<more[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    ll ans=0;
    for(int p=0;p<=n-m;++p){
        for(int j=minn;j<=p;++j){
            ll cur1=more[p][j];
            if( delta+j<0 || delta+j>=N )
                continue;
            ll cur2=more[n-m-p][delta+j];
            ans+=((cur1*cur2)%MOD);
            ans %= MOD;
        }
    }
    cout<<ans<<endl;
}





int main(){
    double tt=clock();
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL
    ios_base::sync_with_stdio(false);
    //cout<<setprecision(20);
    //cout<<fixed;
    solve();
    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}