#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuck1
#define y0 fuck2
#define x1 fuck3
#define y1 fuck4
#define mp make_pair
#define pb push_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=998244353;
ll a[N],b[N];
int n,T;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%lld",b+i);
    ll x=0;
    rep(i,n){
        a[i]=b[i]+x;
        x=max(x,a[i]);
    }
    rep(i,n)printf("%lld%c",a[i]," \n"[i==n]);
    return 0;
}