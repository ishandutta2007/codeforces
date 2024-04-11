#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
const int M=998244353;
int f[maxn],nf[maxn],inv[maxn],n,a[maxn];
int C(int x,int y){return 1ll*nf[y]*f[x]%M*nf[x-y]%M;}

int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    cin >> n;
    for (int i=1;i<=n*2;i++) cin >> a[i];
    sort(a+1,a+n+n+1);
    ll ans=0;
    for (int i=1;i<=n;i++) ans+=a[i+n]-a[i];
    cout << ans%M*C(n*2,n)%M << endl;
}