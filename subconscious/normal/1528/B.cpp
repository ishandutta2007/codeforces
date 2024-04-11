#include <bits/stdc++.h>
#define rep(i,n) for(long long i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckshb
#define y1 fuckhel
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=998244353;
int a[N],s[N],n;
int main(){
    scanf("%d",&n);
    rep(i,n)for(int j=i;j<=n;j+=i)a[j]=(a[j]+1)%mod;
    rep(i,n){
        a[i]=(a[i]+s[i-1])%mod;
        s[i]=(a[i]+s[i-1])%mod;

    }
    printf("%d\n",a[n]);
    return 0;
}