#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N];
ll ans;

int main(){
    cin>>n;
    f(i,1,n+1){
        cin>>a[i];
        //sum[i]=a[i]+sum[i-1];
    }
    for(int i=1;i<=n;i+=2){
        ll sum=0,mn=0;
        f(j,i+1,n+1){
            if(j%2==0){
                ll mx=min(a[j]-sum,1ll*a[i]);
                if(-1*mn<=mx) ans+=mx+mn+1;
                //cout<<i<<" "<<j<<" "<<-1*mn<<" "<<mx<<endl;
                sum-=a[j];
            }
            else
                sum+=a[j];
            //eror(sum);
            minm(mn,sum);
        }
    }
    cout<<ans-(n/2);
}