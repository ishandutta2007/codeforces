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
    int n,m;
    cin>>n>>m;
    char table[n][m];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>table[i][j];
    for(int xplusy=0;xplusy<n+m-1;++xplusy){
        for(int i=0;i<=xplusy;++i){
            int j=xplusy-i;
            if(i<n && j<m){
                if(table[i][j]=='.'){
                    if(xplusy%2)
                        table[i][j]='W';
                    else
                        table[i][j]='B';
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cout<<table[i][j];
        cout<<endl;
    }
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