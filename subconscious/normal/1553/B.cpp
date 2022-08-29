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
int T,n,m;
char s[N],t[N];
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%s",s+1);n=strlen(s+1);
        scanf("%s",t+1);m=strlen(t+1);
        bool S=0;
        rep(i,n)for(int j=i;j<=n;++j){
            int ptr=1;bool flag=1;
            for(int k=i;k<=j;++k)if(t[ptr]!=s[k]){flag=0;break;}else ++ptr;
            for(int k=j-1;ptr<=m;--k)if(k==0||t[ptr]!=s[k]){flag=0;break;}else ++ptr;
            if(flag){S=1;break;}
        }
        puts(S?"YES":"NO");
    }
    return 0;
}