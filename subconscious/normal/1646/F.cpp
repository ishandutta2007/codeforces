#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=105,inf=1e9+7;
int n,a[N][N],s,ans[N*N][N];
int main(){
    scanf("%d",&n);
    rep(i,n)rep(j,n){
        int x;scanf("%d",&x);--x;
        ++a[i][x];
    }
    for(;;){
        int bg=-1;    
        rep(i,n)rep(j,n)if(a[i][j]>1)bg=i;
        if(bg==-1)break;
        rep(i,n){
            int is=-1;
            rep(j,n)if(a[bg][j]>1)is=j;
            ans[s][bg]=is;
            --a[bg][is];
            bg=(bg+1)%n;
            ++a[bg][is];
        }
        ++s;
    }
    rep(i,n)rep(j,i){
        rep(k,n)ans[s][k]=(k+i-j)%n;
        ++s;
    }
    printf("%d\n",s);
    rep(i,s)rep(j,n)printf("%d%c",ans[i][j]+1," \n"[j+1==n]);
    return 0;
}
/*
 
 
*/