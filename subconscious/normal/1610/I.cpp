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
const int N = 3e5+5, inf = 1e9 + 7;
int n,sg[N],ans[N];
vi g[N];
int f[N];bool in[N];
void dfs(int x,int fa){
    f[x]=fa;
    trav(v,g[x])if(v!=f[x]){
        dfs(v,x);
        sg[x]^=(sg[v]+1);
    }
}

int main()
{   
    scanf("%d",&n);
    rep(i,n-1){
        int x,y;scanf("%d%d",&x,&y);
        g[x].pb(y),g[y].pb(x);
    }
    dfs(1,0);
    int s=sg[1];in[1]=1;
    rep(i,n){
        int pos=i;
        while(!in[pos])s^=(sg[pos]+1)^sg[pos]^1,in[pos]=1,pos=f[pos];
        ans[i]=s;
    }
    rep(i,n)printf("%d",ans[i]==0?2:1);
    puts("");
    return 0;
}
/*


n/(2(n-1))
a b -a-b
c d -c-d
-a-c -b-d a+b+c+d

0.25 0.5 0.25
0.5 0 0.5
0.25 0.5 0.25

-1 -1 2
-1 -1 2
2 2 -4
2n:n/n (n+1)/(n-1)
2n+1: (n+1)/n (n+1)/n
1/

-1 -1 1 1
-1 -1 1 1
-1 -1 1 1
3 3 -3 -3
6/2

-1 -1 -1 p p
-1 -1 -1 p p
-1 -1 -1 p p
p p p -1 -1
p p p -1 -1

9/4
12/6

-1 -1 2
2 2 -4
-1 -1 2
1/n^2

up n-1
down 2*(n-1)/(n-2)

3*2*1
2*1

-1 -1 2
-1 -1 2
2 2 -4
-1 -1 1 1
-1 -1 1 1
-1 -1 1 1
3 3 -3 -3

0 0 1
0 0 0.5
*/