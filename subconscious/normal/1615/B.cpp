#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=2e5+5;
int a[30][N],T;
int main(){
    for(int i=0;i<30;++i)
        rep(j,N-1)a[i][j]=a[i][j-1]+((j&(1<<i))==0);
    for(scanf("%d",&T);T--;){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=N;
        for(int i=0;i<30;++i)
            ans=min(ans,a[i][r]-a[i][l-1]);
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/