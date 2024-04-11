#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll arr[3030];
ll can[3030][3030];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    
    cin>>t;
    while(t--){
    	cin>>n>>m;
   		ll i,j,k,a,b,c,d,e,f;
    	for(i=1;i<=n;i++)
    		cin>>arr[i];
    	for(i=1;i<=n;i++)
    		for(j=0;j<=3001;j++)
    			can[i][j]=0;
    	for(i=1;i<=n;i++){
    		for(j=1;j<=m;j++){
    			can[i][(arr[i]/j)+1]++;
    		}
    	}
    	ll ans=5050;
    	for(i=1;i<=n;i++){
    		for(j=1;j<=3001;j++)
    			can[i][j]+=can[i][j-1];
    	}

//    	for(i=1;i<=n;i++){
//    		for(j=0;j<=arr[n];j++)
//    			cout<<i<<' '<<j<<' '<<can[i][j]<<'\n';
//    	}

    	for(ll st=0;st<=arr[1]+1;st++){
    		ll lo=st,hi=arr[n]+2;
    		while(lo<hi){
    			ll fl=0;
    			ll mid=(lo+hi)/2;
    			for(i=1;i<=n;i++){
    				if(can[i][mid]==can[i][st]){
    					fl=1;
    					break;
    				}
    			}
    			if(fl){
    				lo=mid+1;
    			}
    			else{
    				ans=min(ans,mid-st-1);
    				//cout<<st<<' '<<mid<<'\n';
    				hi=mid;
    			}
    		}
    	}
    	cout<<ans<<'\n';
    }
}