//
// Created by artist on 2021/9/30.
//


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define DB1(args...) do { cout << #args << " : "; dbg(args); } while (0)
#define endl '\n'
#define pii pair<int,int>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
using namespace std;
const int N=404;
int n,m,c[N][N],ans,f[N],g[N];
char s[N][N];

void dbg() { std::cout << "  #\n"; }

template<typename T, typename...Args>
void dbg(T a, Args...args) {
    std::cout << a << ' ';
    dbg(args...);
}

void io() { ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); }

int query(int A,int B,int C,int D)
{
    return c[C][D]-c[C][B-1]-c[A-1][D]+c[A-1][B-1];
}

void solve()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,0,n) rep(j,0,m) c[i][j]=0;
    rep(i,1,n) rep(j,1,m) c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+(s[i][j]=='1');
    ans=n*m;
    rep(i,1,n) rep(j,i+4,n)
        {
            rep(k,1,m) f[k]=query(i+1,k,j-1,k),g[k]=(j-i-1-f[k]);
            rep(k,1,m) f[k]+=f[k-1]+(s[i][k]=='0')+(s[j][k]=='0');
            int mx=-n*m;
            rep(k,4,m)
            {
                mx=max(mx,f[k-3]-g[k-3]);
                ans=min(ans,g[k]+f[k-1]-mx);
            }
        }
    printf("%d\n",ans);
}

signed main() {
//    io();
    int T;
//    freopen("out.in","r",stdin);
    scanf("%d",&T);
    while(T--) solve();
    return 0;

}