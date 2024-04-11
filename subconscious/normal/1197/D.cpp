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
int n,m,k,a[N];
ll ans;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    rep(i,n)scanf("%d",a+i);
    ans=0;
    rep(st,min(n,m)){
        ll cur=0;
        for(int i=st;i<=n;i+=m){
            cur-=k;
            for(int j=i;j<i+m&&j<=n;++j)cur+=a[j],ans=max(ans,cur);
            if(cur<0)cur=0;
            ans=max(ans,cur);
        }
    }

    printf("%lld\n",ans);
    return 0;
}