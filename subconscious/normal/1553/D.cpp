#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
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
const int N=2e6+5,mod=1e9+7;
int T,n,m,ans;
char s[N],t[N];
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%s",s+1);n=strlen(s+1);reverse(s+1,s+n+1);
        scanf("%s",t+1);m=strlen(t+1);reverse(t+1,t+m+1);
        int now=1;
        bool flag=1;
        rep(i,m){
            while(now<=n&&s[now]!=t[i])now+=2;
            if(now>n){flag=0;break;}
            ++now;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}