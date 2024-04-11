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
bool check(int x){
    int top=0;
    rep(i,n)if(a[i]!=x)b[++top]=a[i];
    rep(i,top)if(b[i]!=b[top-i+1])return 0;
    return 1;
}
int main()
{

    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        bool flag=1;
        rep(i,n)if(a[i]!=a[n-i+1]){
            flag=check(a[i])||check(a[n-i+1]);
            break;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}
/*
(a,b)=1
a^2+b^2:ab=p:q

p/q=a/b+b/a
*/