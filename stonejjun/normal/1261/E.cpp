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

ll arr[5050];
ll brr[1010];
ll ans[1010][1010];

ll n,m;

bool sf(ll a,ll b){
    return arr[a]>arr[b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll i,j,k,l;
    cin>>n;
    
    for(i=1;i<=n;i++){
        cin>>arr[i];
        brr[i]=i;
    }

    sort(brr+1,brr+1+n,sf);
    ll x=arr[brr[1]]+1;

    for(i=1;i<=n;i++){
        ll k=brr[i];
        for(j=i-1;j<i-1+arr[k];j++){
            ans[j%x][k]=1;
        }
    }

    cout<<x<<'\n';
    for(i=0;i<x;i++){
        for(j=1;j<=n;j++)
            cout<<ans[i][j];
        cout<<'\n';
    }

}