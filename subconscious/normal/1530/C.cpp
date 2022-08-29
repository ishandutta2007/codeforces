#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
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
const int N=2e6+5,mod=998244353;
const ld eps=1e-10;
int a[N],b[N],n,T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        sort(a+1,a+n+1);rep(i,3*n)a[n+i]=100;
        rep(i,4*n)a[i]+=a[i-1];
        rep(i,n)scanf("%d",b+i);
        sort(b+1,b+n+1,greater<int>());
        rep(i,3*n)b[n+i]=0;
        rep(i,4*n)b[i]+=b[i-1];
        int l=-1,r=3*n;
        while(l+1<r){
            int mid=(l+r)/2;
            int num=(n+mid)-(n+mid)/4;
            ll x=(a[n+mid]-a[n+mid-num])-(b[num]-b[0]);
            if(x>=0)r=mid;else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}
/*
*/