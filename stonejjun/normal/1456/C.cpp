#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;
 
#define ff first
#define ss second
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);
 
struct poi{
    ll val,xx,yy;
};
 
vector<ll> x;
ll n,m;
ll mod=998244353;
string s;
string t;
ll arr[1010101];
ll brr[1010101];
 
vector<ll> v[1010101];
ll pre[1010101];

bool sf(ll a,ll b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,a,b,c;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+1+n,sf);

   
    ll ans=-1e18;

    ll val=0;
    ll now=0;
    ll cnt=0;
    ll fin=n;
    ll chk=1e18;
    for(i=1;i<=n;i++){
        val+=now;
        now+=arr[i];
        if(now<0){
            arr[i]=now;
            chk=i;
            break;
        }
    }

   // cout<<val<<'\n';

    for(i=n;i>=chk;i--){
        val+=arr[i]*(ll)(cnt/(m+1));
        cnt++;
    }
    cout<<val;
    
    
    
}