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
     
    int n,r,ans,dp[N],mx[N],t[N],x[N],y[N];
     
    int main(){
        cin>>r>>n;
        x[0]=y[0]=1;
        f(i,1,n+1){
            dp[i]=-N;
            cin>>t[i]>>x[i]>>y[i];
            f_(j,i-1,max(0,i-1000))
                if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
                    maxm(dp[i],dp[j]+1);
            if(1000<i) maxm(dp[i],mx[i-1000]+1);
            mx[i]=max(mx[i-1],dp[i]);
            maxm(ans,dp[i]);
          //  cout<<dp[i]<<endl;
        }
        cout<<ans;
    }