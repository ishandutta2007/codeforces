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

struct poi{
    ll u,a,b;
};

vector<poi> v[1101010];
vector<ll> x;
ll arr[1010101];
ll ans=0;
ll n,m;
ll mod=998244353;
ll vis[1010101];
ll val[1010101];
ll mul[1010101];
ll pmul[1010101];
ll fin[1010101];
string s;
ll chk[1010];
ll chk2[1010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    cin>>t;

    while(t--){

        ll i,j,k,l;
        ll a,b;

        cin>>a>>b;
        n=b-a+1;

        //ll chk=1;
        for(i=0;i<20;i++){
            chk[i]=0;
            chk2[i]=0;
        }

        for(i=0;i<n;i++){
            for(j=0;j<18;j++)
                if(i&(1<<j))
                    chk[j]++;
        }

        for(i=1;i<=n;i++){
            cin>>arr[i];

            for(j=0;j<18;j++)
                if(arr[i]&(1<<j))
                    chk2[j]++;
        }

        ll ans=0;

        for(i=0;i<18;i++){
            if(chk[i]!=chk2[i])
                ans+=(1<<i);
        }
        cout<<ans<<'\n';


    }


    
    
}