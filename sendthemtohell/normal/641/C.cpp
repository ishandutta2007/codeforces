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
const int MOD=1000*1000*1000+7;
const int N=15;

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

int ans[1000*1000+228];

void solve(ld tt){
    int kek=0,lol=1,n,qq,boy=0;
    scanf("%d%d",&n,&qq);
    //cin>>n>>qq;
    for(int i=0;i<qq;++i){
        int q;
        scanf("%d",&q);
        //cin>>q;
        if(q==2){
            if (kek%2){
                kek-=1;
                lol+=1;
            }else{
                kek+=1;
                lol-=1;
            }
        }else{
            int r;
            //cin>>r;
            scanf("%d",&r);
            kek += n+r;
            kek %= n;
            lol += n+r;
            lol %= n;
        }
    }
    while(ans[kek]==0){
        ans[kek]=boy+1;
        kek+=2;
        kek %=n;
        boy+=2;
        boy%=n;
    }
    boy=1;
    while(ans[lol]==0){
        ans[lol]=boy+1;
        lol+=2;
        lol %=n;
        boy+=2;
        boy%=n;
    }
    for(int i=0;i<n;++i){
        printf("%d ",ans[i]);
        //cout<<ans[i]<<" ";
    }
    printf("\n");
    //cout<<endl;
}




int main(){
    ld tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #else
//        freopen("","r",stdin);
//        freopen("","w",stdout);
    #endif // LOCAL

//    speedup
//    coutdouble

    solve(tt);

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL

    return 0;
}