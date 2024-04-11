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
int T,n,a[N],tot;
int main()
{

    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        int ans=0;
        rep(i,n)if(i==1||a[i]!=a[i-1]){
            int now=i,cnt=1;
            while(now<n&&a[now+1]==a[i])++now,++cnt;
            if(now<n){
                ++now,++cnt;
                for(;;){
                    int ind=lower_bound(a+now+1,a+n+1,2*a[now]-a[i])-a;
                    if(ind==n+1)break;
                    now=ind,++cnt;
                }
            }
            ans=max(ans,cnt);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
/*
(a,b)=1
a^2+b^2:ab=p:q

p/q=a/b+b/a
*/