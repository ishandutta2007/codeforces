#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=200000+10;
const double EPS = 1e-8;
int n,k;
char s[102][102];
int ans[102][102];
bool ok(int x,int y){
    return x<=n&&x>=1&&y<=n&&y>=1&&s[x][y]=='.';
}
void solve(int x,int y){
    bool ac=1;
    rep(i,0,k-1){
        if(!ok(x+i,y)) ac=0;
    }
    if(ac) rep(i,0,k-1) ans[x+i][y]++;

    ac=1;
    rep(i,0,k-1){
        if(!ok(x,y+i)) ac=0;
    }
    if(ac) rep(i,0,k-1) ans[x][y+i]++;
}
int main(){
    rd(n),rd(k);
    rep(i,1,n)scanf("%s",s[i]+1);
    
    int px=1,py=1,bst=0;
    rep(i,1,n){
        rep(j,1,n){
            solve(i,j);
        }
    }
    rep(i,1,n)rep(j,1,n) if(ans[i][j]>bst) px=i,py=j,bst=ans[i][j];
    //printf("%d\n", bst);
    printf("%d %d\n", px,py);
}