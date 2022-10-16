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

const int MOD=1000*1000*1000+7;
const int N=101;

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

int dp[N][N];

void solve(ld tt){
    int n,k,d;
    cin>>n>>k>>d;
    dp[1][1]=1;
    dp[0][1]=1;
    for(int i=2;i<N;++i){
        for(int j=1;j<N;++j){
            for(int tree=1;tree<=k;++tree){
                if(i>=tree){
                    if(tree>=j){
                        dp[i][j] += dp[i-tree][1];
                    }else{
                        dp[i][j] += dp[i-tree][j];
                    }
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout<<dp[n][d]<<endl;
}




int main(){
    ld tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //cout<<setprecision(20);
    //cout<<fixed;

    solve(tt);

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}