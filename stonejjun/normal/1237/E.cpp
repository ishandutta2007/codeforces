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
ll mod=998244353;
ll arr[1010101];
ll lst[1010101];
ll chk[1010101];
ll tree[4040404];
ll r[1010101];
ll val[1010101];
ll dp[1010101];

ll n,m;
ll inf=1e18;
ll mval;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;

    ll i,j,k,l;
//    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;

    ll fl=2;
    while(fl<=1000000){
        dp[fl]=dp[fl-1]=1;
        if(fl%2) fl*=2;
        else fl=fl+fl+1;
    }
    cin>>n;
    cout<<dp[n];
    
}