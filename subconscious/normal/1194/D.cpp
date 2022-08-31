#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long double ld;
const int N=1e6+5;
int sg[N],T,n,k;
int main(){
    sg[0]=0;
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&k);
        int ans;
        if(k%3==0){
            n%=k+1;
            if(n==k)ans=3;else ans=n%3;
        }else ans=n%3;
        puts(ans!=0?"Alice":"Bob");
    }

    return 0;
}