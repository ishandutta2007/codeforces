#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define mp make_pair
#define pb push_back
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklbn
#define y1 fuckyzc
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld eps=1e-10,inf=1e50;
const int mod=1e9+7,N=3e5+5;
int n,k,a[N],b[N],mi,mx;
int main(){
    scanf("%d%d",&n,&k);
    rep(i,n)scanf("%d",a+i);
    if(n==1){puts("0");return 0;}
    rep(i,n-1)b[i]=a[i+1]-a[i];
    k=n-k;--n;
    sort(b+1,b+n+1);
    int ans=0;rep(i,k)ans+=b[i];
    printf("%d\n",ans);
    return 0;
}