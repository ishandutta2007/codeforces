#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckjsb
#define y1 fuckjtjl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=0x3f3f3f3f,MOD=1e9+7;
int a[N],n;bool is[N];
int main(){
    scanf("%d",&n);
    int cur=0;
    rep(i,n){
        scanf("%d",a+i);
        if(a[i]>cur){printf("%d\n",i);return 0;}
        is[a[i]]=1;
        while(is[cur])++cur;
    }
    puts("-1");
    return 0;
}