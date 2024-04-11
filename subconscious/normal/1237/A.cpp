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
const ld eps=1e-9;
const int N=(int)2e6+5;
int n,a[N];bool typ;
int main(){
    scanf("%d",&n);
    rep(i,n){
        scanf("%d",a+i);
        if(a[i]%2==0)a[i]=a[i]/2;
        else a[i]=(a[i]+((typ)?1:-1))/2,typ^=1;
    }
    rep(i,n)printf("%d\n",a[i]);
    return 0;
}