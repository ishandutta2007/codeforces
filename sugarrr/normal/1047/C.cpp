#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////

int N=15000000;///

vector<int>prime;
void calprime(){
    bool pri[N+5];
    rep(i,2,N)pri[i]=true;
    rep(i,2,N){
        if(pri[i]){
            prime.pb(i);
            for(int j=2*i;j<=N;j+=i){
                pri[j]=false;
            }
        }
    }
}

int gcd(int a,int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    else return gcd(b%a,a);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    calprime();

    int n;cin>>n;
    int a[n];rep(i,0,n-1)cin>>a[i];
    bool flag=false;
    rep(i,0,n-2)if(a[i]!=a[i+1])flag=true;
    if(!flag){
        cout<<-1<<endl;
        return 0;
    }
    int g=a[0];
    rep(i,1,n-1){
        g=gcd(g,a[i]);
    }
    rep(i,0,n-1){
        a[i]=a[i]/g;
    }
    
    int psize=prime.size();
    int c[psize];
    rep(i,0,psize-1){
        c[i]=0;
    }
    rep(i,0,n-1){
        int m=a[i];
        for(int j=0;j<=psize-1;j++){
            if(prime[j]*prime[j]>a[i])break;
            if(a[i]%prime[j]==0){
                c[j]++;
                a[i]/=prime[j];
                while(a[i]%prime[j]==0){
                    a[i]/=prime[j];
                }
            }
        }
        int pos=lower_bound(prime.begin(),prime.end(),a[i])-prime.begin();
        if(prime[pos]==a[i]){
            c[pos]++;
        }
    }
    /*rep(i,0,10){
        cout<<c[i].first<<" "<<c[i].second<<endl;
    }*/
    int ma=0;
    rep(i,0,psize-1){
        ma=max(ma,c[i]);
    }
    int ans=n-ma;
    cout<<ans<<endl;
    
    
    return 0;
}