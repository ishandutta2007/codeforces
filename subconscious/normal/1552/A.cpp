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
const int N=1e6+5,inf=1e9+7;
int a[N],n,T;
char s[N],t[N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s",s+1);
        rep(i,n)t[i]=s[i];
        sort(t+1,t+n+1);
        int ans=n;
        rep(i,n)if(t[i]==s[i])--ans;
        printf("%d\n",ans);
    }

    return 0;
}