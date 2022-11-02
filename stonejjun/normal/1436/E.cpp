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
ll n,m;
ll inf=1e18;
ll mval;

ll upt(ll idx,ll val,ll s,ll e,ll nod){
    if(idx>e||idx<s) return tree[nod];
    if(s==e){
        return tree[nod]=val;
    }
    return tree[nod]=min(upt(idx,val,s,(s+e)/2,nod*2),upt(idx,val,(s+e)/2+1,e,nod*2+1));
}

ll sol(ll l,ll r,ll s,ll e,ll nod){
    if(r<s||e<l) return 1e9;
    if(l<=s&&e<=r) return tree[nod];
    return min(sol(l,r,s,(s+e)/2,nod*2),sol(l,r,(s+e)/2+1,e,nod*2+1)); 
}

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

    cin>>n;
    ll chk1=0;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]!=1) chk1=1;
    }
    if(!chk1){
        cout<<1;
        return 0;
    }

    for(i=1;i<=n;i++){
        ll x=arr[i];
        if(lst[x]==i-1){
            lst[x]++;
            upt(x,i,1,n,1);
            continue;
        }
        ll y=sol(1,x-1,1,n,1);
        if(y>lst[x]) chk[x]=1;
        lst[x]=i;
        upt(x,i,1,n,1);
    }

    for(i=1;i<=n+1;i++){
        if(sol(1,i-1,1,n,1)>lst[i]) chk[i]=1;
    }

    for(i=1;i<=n+2;i++)
        if(chk[i]==0){
            cout<<i;
            return 0;
        }

}