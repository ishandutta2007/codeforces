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
    int n;
    cin>>n;
    vector<int> length;
    for(int i=0;i<n;++i){
        int nxt;
        cin>>nxt;
        length.pb(nxt);
    }
    int s,f;
    int goeast=0,gowest=0;
    cin>>s>>f;
    --s,--f;
    for(int i=s;i!=f;i=(i+1)%n){
        goeast += length[i];
    }
    for(int i=(s-1+n)%n;;i=(i-1+n)%n){
        gowest += length[i];
        if(i == f)
            break;
    }
    //cout<<goeast<<"  "<<gowest<<endl;
    cout<<min(goeast,gowest)<<endl;
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