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
const int N=4000+5,mod=1e9+7;
const ll inf=1e18;
int T,n,c[N][N];
char s[N],t[N];
int cnt[2][3][N];
int C(int n,int m){
    if(m>n)return 0;
    if(m<0)return 0;
    return c[n][m];
}
int main(){
    c[0][0]=1;
    rep(i,N-1){
        c[i][0]=1;
        rep(j,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s",s+1),scanf("%s",t+1);
        rep(i,n/2){
            if(s[i<<1]!='?')s[i<<1]='1'-s[i<<1]+'0';
            if(t[i<<1]!='?')t[i<<1]='1'-t[i<<1]+'0';
        }
        rep(i,n){
            for(int j=0;j<3;++j)cnt[0][j][i]=cnt[0][j][i-1];
            if(s[i]=='0')++cnt[0][0][i];
            else if(s[i]=='1')++cnt[0][1][i];
            else ++cnt[0][2][i];
        }
        rep(i,n){
            for(int j=0;j<3;++j)cnt[1][j][i]=cnt[1][j][i-1];
            if(t[i]=='0')++cnt[1][0][i];
            else if(t[i]=='1')++cnt[1][1][i];
            else ++cnt[1][2][i];
        }
        int ans=0;
        rep(i,n)if(s[i]!='0')rep(j,n)if(t[j]!='0'){
            int C1=C(
                cnt[0][2][i-1]+cnt[1][2][j-1],
                cnt[0][2][i-1]+cnt[0][1][i-1]-cnt[1][1][j-1]
            );
            int C2=C(
                cnt[0][2][n]-cnt[0][2][i]+cnt[1][2][n]-cnt[1][2][j],
                (cnt[0][2][n]-cnt[0][2][i])+(cnt[0][1][n]-cnt[0][1][i])-(cnt[1][1][n]-cnt[1][1][j])
            );
            //if(C1*C2*abs(i-j)>0)printf("%d %d %d\n",i,j,C1*C2*abs(i-j));
            ans=(ans+(ll)C1*C2%mod*abs(i-j))%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/