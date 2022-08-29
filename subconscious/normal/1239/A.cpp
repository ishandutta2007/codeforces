#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld eps=1e-9;
const int N=(int)2e6+5,mod=1e9+7;
int n,m,f[N];
int main(){
    scanf("%d%d",&n,&m);
    f[0]=1,f[1]=2,f[2]=4;
    for(int i=3;i<=max(n,m);++i)f[i]=(f[i-1]+f[i-2])%mod;
    printf("%d\n",(f[n]+f[m]-2)%mod);
    return 0;
}