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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    cin>>t;

    while(t--){

        ll i,j,k,l;
        cin>>n;
        cin>>s;
        ll ans=0;
        for(i=0;i<n;i++){
            if(i<n-1&&s[i]=='0'&&s[i+1]=='0'){
                ans+=2;
            }
            else if(i<n-2&&s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0'){
                ans+=1;
            }

        }
        cout<<ans<<'\n';        

    }


    
    
}