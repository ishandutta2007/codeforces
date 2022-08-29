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
const int N = 2e5+5, inf = 1e9 + 7;
int T,n,a[N],b[N];
int main()
{

    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d%d",a+i,b+i);
        int l=0,r=n+1;
        while(l+1<r){
            int mid=(l+r)/2,cnt=0;
            rep(i,n)if(cnt<mid&&cnt<=b[i]&&mid-1-cnt<=a[i])++cnt;
            if(cnt==mid)l=mid;else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
/*
(a,b)=1
a^2+b^2:ab=p:q

p/q=a/b+b/a
*/