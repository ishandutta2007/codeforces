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
ll pre[1010101];
ll chk[1010101];
ll brr[1010101];

bool sf(ll a,ll b){
    return arr[a]>arr[b];
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll i,j,k,a,b,c;
    cin>>n>>m;
    ll all=0;

    cout<<"? ";
    for(i=1;i<=m;i++)
        cout<<"1";
    cout<<endl;

    cin>>all;

    for(i=1;i<=m;i++){
        cout<<"? ";
        for(j=1;j<=m;j++){
            if(j==i) cout<<"1";
            else cout<<"0";
        }
        cout<<endl; 
        cin>>arr[i];
    }

    

    for(i=1;i<=m;i++){
        chk[i]=1;
        brr[i]=i;
    }

    sort(brr+1,brr+1+m,sf);
  //  for(i=1;i<=m;i++)
       // cout<<i<<' '<<brr[i]<<'\n';

    for(ll x=1;x<m;x++){
        i=brr[x];
        ll newval=0;

        cout<<"? ";
        for(j=1;j<=m;j++){
            if(j==i) cout<<"0";
            else if(chk[j]==0) cout<<"0";
            else cout<<"1";
        }
        cout<<endl; 
        cin>>newval;
        if(newval!=all-arr[i]) chk[i]=0;
        else newval+=arr[i];
        //cout<<i<<' '<<all<<' '<<arr[i]<<' '<<all-arr[i]<<' '<<newval<<'\n';
        all=newval;
    }

    ll ans=0;
    for(i=1;i<=m;i++)
        ans+=arr[i]*chk[i];

    cout<<"! "<<ans<<endl;
    return 0;


}