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

void solve(){
    int remn[5]={0},remm[5]={0};
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=max(n,m);++i){
        if(i<=n)
            ++remn[i%5];
        if(i<=m)
            ++remm[i%5];
    }
    cout<<1LL*remn[0]*remm[0]+1LL*remn[1]*remm[4]+1LL*remn[2]*remm[3]+1LL*remn[3]*remm[2]+1LL*remn[4]*remm[1]<<endl;
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