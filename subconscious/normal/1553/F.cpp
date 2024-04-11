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
const int N=3e5+10,mod=1e9+7;
int a[N],n;
ll t[3][N];
void add(ll t[],int p,ll x){
    p+=5;
    for(;p<N;p+=p&-p)t[p]+=x;
}
ll que(ll t[],int p){
    p+=5;
    ll s=0;
    for(;p;p-=p&-p)s+=t[p];
    return s;
}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    ll ans=0;
    rep(i,n){
        for(int j=a[i];j<N;j+=a[i]){
            ll num=que(t[0],min(j+a[i]-1,N-1))-que(t[0],j-1);
            ll sum=que(t[1],min(j+a[i]-1,N-1))-que(t[1],j-1);
            //if(num>0)printf("s:%lld %lld\n",num,sum);
            ans+=sum-num*j;
            ans+=num*a[i];
        }
        ll num=que(t[0],a[i]);
        ll sum=que(t[2],a[i]);
        //printf("%lld %lld\n",num,sum);
        ans+=num*a[i]-sum;
        ans+=que(t[1],a[i]);
        add(t[0],a[i],1);add(t[1],a[i],a[i]);
        for(int j=a[i];j<N;j+=a[i]){
            add(t[2],j,a[i]);
        }
        printf("%lld%c",ans," \n"[i==n]);
    }
    // ans=0;
    // rep(i,n){
    //     rep(j,i)ans+=a[i]%a[j]+a[j]%a[i];
    //     printf("%lld%c",ans," \n"[i==n]);
    // }
    return 0;
}