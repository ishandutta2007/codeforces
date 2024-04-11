#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckyzx
#define y0 fuckyxc
#define x1 fuckxzc
#define y1 fucxyzc
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-12;
int c[N],p[N],n;
int main(){
    scanf("%d",&n);
    rep(i,n-1)scanf("%d",p+i+1);
    rev(i,n){
        if(c[i]==0)c[i]=1;
        c[p[i]]+=c[i];
    }
    sort(c+1,c+n+1);
    rep(i,n)printf("%d%c",c[i]," \n"[i==n]);
    return 0;
}