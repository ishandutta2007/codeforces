#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
#define y second
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int N=3228;
const int MOD=1000*1000*1000+7;

ll pw(ll a,int x){
    if(!x)
        return 1;
    if(x%2)
        return a*pw(a*a,x/2);
    return pw(a*a,x/2);
}

void solve(){
    int n,t;
    cin>>n>>t;
    vector<ll> tm;
    tm.pb(0);
    for(int i=1;i<=n;++i){
        ll nxt;
        cin>>nxt;
        tm.pb(tm[i-1]+nxt);
    }
    int mx=0;
    for(int i=1;i<=n;++i){
        int rgt=i,lft=-1;
        while(rgt-lft>1){
            int mid=(rgt+lft)/2;
            if(tm[i]-tm[mid]<=t)
                rgt=mid;
            else
                lft=mid;
        }
        mx=max(mx,i-rgt);
    }
    cout<<mx<<endl;
}




int main(){
    double tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //cout<<setprecision(20);
    //cout<<fixed;

    solve();

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}