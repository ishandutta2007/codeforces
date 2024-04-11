#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define res(i,n) for(int i=0;i<n;++i)
#define eb emplace_back
#define mp make_pair
#define x0 fuckcjb
#define y0 fuckcxb
#define x1 fuckxjb
#define y1 fuckcjx
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=55,mod=1e9+7;
const ld eps=1e-9,inf=1e50;
int n,ans[N][N][N][N];
char s[N][N];
void upd(int&x,int y){if(x>y)x=y;}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%s",s[i]+1);
    for(int lenx=1;lenx<=n;++lenx)
        for(int i=1,j=i+lenx-1;j<=n;++i,j=i+lenx-1)
            for(int leny=1;leny<=n;++leny)
                for(int k=1,p=k+leny-1;p<=n;++k,p=k+leny-1){
                    ans[i][j][k][p]=max(j-i+1,p-k+1);
                    if(i==j&&k==p&&s[i][k]=='.')ans[i][j][k][p]=0;
                    for(int c=i;c<j;++c)
                        upd(ans[i][j][k][p],ans[i][c][k][p]+ans[c+1][j][k][p]);
                    for(int c=k;c<p;++c)
                        upd(ans[i][j][k][p],ans[i][j][k][c]+ans[i][j][c+1][p]);
                    //printf("%d %d %d %d %d\n",i,j,k,p,ans[i][j][k][])
                }
    printf("%d\n",ans[1][n][1][n]);
    return 0;
}