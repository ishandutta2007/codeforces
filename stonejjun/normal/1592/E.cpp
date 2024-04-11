#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);

ll arr[1010101];
ll brr[1010101];
ll pre[4010104];
ll tp=19;

ll n,m;
ll x;
ll ans=0;

void sol(ll l,ll r){
 //   cout<<"qwe"<<x<<' '<<l<<' '<<r<<'\n';
    ll i,j,k;
    ll val=0;
    pre[0]=l;
    for(i=l;i<=r;i++){
        val^=brr[i];
      //  cout<<i<<' '<<brr[i]<<' '<<val<<'\n';
        if(pre[val]==0){
            pre[val]=i+1;
        }
        else{
            ans=max(ans,i+1-pre[val]);
        }
    }
    val=0;
    for(i=l;i<=r;i++){
        val^=brr[i];
        pre[val]=0;
    }
    //cout<<ans<<'\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll i,j,k,l;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    ll fl=0;

    for(ll msk=19;msk>=0;msk--){
        x=(1<<msk);
        fl+=x;
        for(i=1;i<=n;i++){
            brr[i]=0;
            if(arr[i]&x){
                brr[i]=arr[i]&fl;
            }
        }
        ll st=0;
        for(i=1;i<=n+1;i++){
            if(brr[i]&&brr[i-1]==0){
                st=i;
            }
            if(brr[i]==0&&brr[i-1]){
                sol(st,i-1);
            }
        }
    }

    cout<<ans;

}