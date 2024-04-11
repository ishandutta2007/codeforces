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
ll arr[1010101];
ll pre[1010101];
ll suf[1010101];

vector<ll> v[1010101];
ll chk[1010101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
   		ll i,j,k,a,b,c,d,e,f;
   		cin>>n>>m;
   		for(i=0;i<=n+10;i++){
   			pre[i]=suf[i]=0;
   		}

   		for(i=1;i<=n;i++){
   			cin>>arr[i];
   		}

   		for(i=2;i<=n;i++){
   			pre[i]=pre[i-1];
   			if(arr[i]<arr[i-1]) pre[i]+=arr[i-1]-arr[i]; 
   		}

   		for(i=n-1;i>=1;i--){
   			suf[i]=suf[i+1];
   			if(arr[i]<arr[i+1]) suf[i]+=arr[i+1]-arr[i]; 
   		}	

   		while(m--){
   			cin>>a>>b;
   			if(a<=b){
   				cout<<pre[b]-pre[a]<<'\n';
   			}
   			else cout<<suf[b]-suf[a]<<'\n';
   		}
   	
}