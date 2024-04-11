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
    int pl[3]={0};
    int n,p1,p2;
    cin>>n>>p1>>p2;
    pl[1]-=p1;
    pl[2]-=p2;
    for(int i=0;i<n;++i){
        int nxt;
        cin>>nxt;
        if(nxt==2 && pl[2]>=0)
            ++pl[1];
        else
            ++pl[nxt];
    }
    cout<<max(0,pl[1])+max(0,pl[2]);
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