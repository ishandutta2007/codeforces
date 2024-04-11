#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss secondac
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
vector<ll> v[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll i,j,k;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        sort(arr+1,arr+1+n);
        ll ans=0;
        ll val=0;
        ans+=arr[n];
        for(i=2;i<=n;i++){
            ans-=(arr[i]*(i-1))-val;
            val+=arr[i];
        }
        cout<<ans<<'\n';
    }
}