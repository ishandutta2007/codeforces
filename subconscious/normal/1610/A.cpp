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
const int N = 1e7+5, inf = 1e9 + 7;
int T,n,m;
int main()
{

    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        if(n==1&m==1)puts("0");
        else if(n==1||m==1)puts("1");
        else puts("2");
    }
    return 0;
}
/*
(a,b)=1
a^2+b^2:ab=p:q

p/q=a/b+b/a
*/