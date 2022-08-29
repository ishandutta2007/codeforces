#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckyzx
#define y0 fuckyxc
#define x1 fuckxzc
#define y1 fucxyzc
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-12;
int a[N],n;
int main(){
    scanf("%d",&n);int r;
    rep(i,n){
        scanf("%d",&r);int x;
        rep(j,r)scanf("%d",&x),++a[x];
    }
    bool flag=0;
    rep(i,100)if(a[i]==n){
        if(flag)printf(" ");else flag=1;
        printf("%d",i);
    }
    puts("");
    return 0;
}