#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=1e9+7;
int a[N],n,m;
int main(){
    scanf("%d%d",&n,&m);
    int now=1;
    for(;now<=n;++now){
        if(m==0){a[now]=a[now-1]*2+50000;break;}
        if(m>=(now-1)/2){a[now]=now;m-=(now-1)/2;}
        else{
            a[now]=a[now-1]+a[now-2*m];
            m=0;
            break;
        }
    }
    a[now+1]=a[now]*2+70000;
    for(int i=now+2;i<=n;++i)a[i]=a[i-1]+70000;
    if(m!=0)puts("-1");else rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
}