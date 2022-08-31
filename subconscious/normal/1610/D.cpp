#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= n; ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckcjb
#define x1 fuckjsb
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;
typedef vector<int> vi;
const int N = 2e5+5, mod = 1e9 + 7;
int T,n,a[40],tot;
int pw(int x,int y){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
int main()
{
    scanf("%d",&n);
    tot=0;
    rep(i,32)a[i]=0;
    rep(i,n){
        int x;
        scanf("%d",&x);
        if(x%2==0){
            int cnt=0;
            while(x%2==0)x/=2,++cnt;
            a[cnt]++;
            ++tot;
        }    
    }
    int ans=(pw(2,n)-1+mod)%mod;
    rep(i,32)if(a[i]>0){
        tot-=a[i];
        ans=(ans-pw(2,a[i]+tot-1)+mod)%mod;
    }
    printf("%d\n",ans);
    return 0;
}
/*
(a,b)=1
a^2+b^2:ab=p:q

p/q=a/b+b/a
*/