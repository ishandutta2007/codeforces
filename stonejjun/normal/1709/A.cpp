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
vector<ll> v[1010101];
ll chk[1010101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
   		ll i,j,k,a,b,c,d,e,f;
   		cin>>m;
   		n=3;
   		for(i=1;i<=n;i++)
   			chk[i]=0;
   		for(i=1;i<=n;i++){
   			cin>>arr[i];
   		}
   		chk[m]=1;
   		m=arr[m];

   		chk[m]=1;
   		m=arr[m];

   		chk[m]=1;
   		m=arr[m];

   		ll fl=1;
   		for(i=1;i<=n;i++)
   			if(chk[i]==0) fl=0;

   		if(fl)
   			cout<<"YES"<<'\n';
   		else cout<<"NO"<<'\n';
   	}
}