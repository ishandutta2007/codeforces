#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long double ld;
const int N=4e5+5;
int T,n,m,a[N],b[N];
char s[N];
int main(){
    
    for(cin>>T;T--;){
        cin>>n>>m;
        rep(i,n)scanf("%s",s+i*m);
        rep(i,n)a[i]=0;rep(j,m)b[j]=0;
        rep(i,n)rep(j,m)if(s[i*m+j]=='.')++a[i],++b[j];
        int ans=1e9+7;
        rep(i,n)rep(j,m)ans=min(ans,a[i]+b[j]-(s[i*m+j]=='.'));
        printf("%d\n",ans);
    }

    return 0;
}