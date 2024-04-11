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
int T,n,c[2][2];
char s[N],t[N];
int main(){
    for(scanf("%d",&T);T--;){
        c[0][0]=c[0][1]=c[1][0]=c[1][1]=0;
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        rep(i,n)c[s[i]-'0'][t[i]-'0']++;
        int ans=N;
        if(c[0][1]==c[1][0])ans=min(ans,c[0][1]*2);
        if(c[1][1]==c[0][0]+1)ans=min(ans,c[1][1]*2-1);
        if(ans==N)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/