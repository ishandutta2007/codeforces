#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int N=3228;
const int MOD=1000*1000*1000+7;

void solve(){
    int n,dist=0,j=0;
    ll ans=0;
    bool opex=0;
    cin>>n;
    while(!opex && j<n){
        cin>>opex;
        ++j;
    }
    if(opex)
        ans=1;
    for(int i=j;i<n;++i){
            cin>>opex;
            ++dist;
            if(opex){
                ans*=dist;
                dist=0;
            }
    }
    cout<<ans<<endl;
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