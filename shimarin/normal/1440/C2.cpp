#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 110;
int n,m,a[N][N];
char s[N][N];
struct node{
    int a,b,c,d,e,f;
};
inline void solve(){
    n=read(),m=read();
    FOR(i,0,n) scanf("%s",s[i]);
    FOR(i,0,n) FOR(j,0,m) a[i][j]=s[i][j]-'0';
    vector<node>ans;
    auto change=[&](int x1,int y1,int x2,int y2,int x3,int y3){
        ans.pb((node){x1,y1,x2,y2,x3,y3});
        a[x1][y1]^=1,a[x2][y2]^=1,a[x3][y3]^=1;
    };
    Dow(i,n-1,2) FOR(j,0,m) if (a[i][j]){
        if (j) change(i,j,i-1,j,i-1,j-1);
            else change(i,j,i-1,j,i-1,j+1);
    }
    Dow(i,m-1,2){
        if (a[0][i]) change(0,i,0,i-1,1,i-1);
        if (a[1][i]) change(1,i,1,i-1,0,i-1);
    }
    if (a[1][1]) change(0,1,1,0,1,1);
    
    if (a[0][0]+a[0][1]+a[1][0]==3) change(0,0,0,1,1,0);
    else if (a[0][0]+a[0][1]==2){
        change(0,0,1,0,1,1);
        change(0,1,1,0,1,1);
    } else if (a[0][0]+a[1][0]==2){
        change(0,0,0,1,1,1);
        change(1,0,0,1,1,1);
    } else if (a[1][0]+a[0][1]==2) {
        change(1,0,0,0,1,1);
        change(0,1,0,0,1,1);
    } else if (a[0][0]==1){
        change(0,0,0,1,1,0);
        change(0,0,0,1,1,1);
        change(0,0,1,1,1,0);
    } else if (a[0][1]==1){
        change(0,1,0,0,1,1);
        change(0,1,0,0,1,0);
        change(0,1,1,0,1,1);
    } else if (a[1][0]==1){
        change(1,0,1,1,0,0);
        change(1,0,1,1,0,1);
        change(1,0,0,1,0,0);
    }
    FOR(i,0,n) FOR(j,0,m) assert(a[i][j]==0);
    printf("%d\n",siz(ans));
    for (auto i:ans) printf("%d %d %d %d %d %d\n",i.a+1,i.b+1,i.c+1,i.d+1,i.e+1,i.f+1);
}

int main() {
    int T=read();
    while (T--) solve();
}