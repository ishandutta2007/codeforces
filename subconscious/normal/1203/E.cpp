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
const double eps=1e-9;
const int N=(int)1.5e5+5;
int a[N],n;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int now=0,ans=0;
    rep(i,n)for(int j=-1;j<=1;++j)if(now<a[i]+j){
        now=a[i]+j;
        ++ans;
        break;
    }
    printf("%d\n",ans);
    return 0;
}