#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define eb emplace_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=1e9+7;
const ld eps=1e-12;
int b,g,n;
int main(){
    scanf("%d%d%d",&b,&g,&n);
    printf("%d\n",min(n,b)-max(0,n-g)+1);
    return 0;
}