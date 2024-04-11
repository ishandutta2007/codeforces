#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,mod=1e9+7;
const ld eps=1e-12;
ll a,b,c;
int main(){
    scanf("%lld%lld%lld",&a,&b,&c);
    ll tmp=min(a,b);

    printf("%lld\n",2*c+tmp*2+(a!=tmp||b!=tmp));
}